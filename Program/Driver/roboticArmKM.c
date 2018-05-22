#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h>

/* ============== ACCESO AL KERNEL EN TTYACM0 ============= */

static struct file *device_open(const char *filename, int flags, umode_t mode)
{
    return filp_open(filename, 0, O_RDWR);
}

static ssize_t device_write(struct file *f, const char *buf, int count)
{

    int result;
    mm_segment_t oldfs;

    oldfs = get_fs();
    set_fs(KERNEL_DS);
    f->f_pos = 0;
    result = f->f_op->write(f, buf, count, &f->f_pos);
    set_fs(oldfs);

    return result;
}

static void dev_close(struct file *device, fl_owner_t id)
{
        filp_close(device, id);
}

/* =============== OPERACIONES CON ARCHIVOS DE DISPOSITIVOS ===================== */
DEFINE_MUTEX(xmutex);
static struct file *device = NULL;
static int xdev_open(struct inode *inode, struct file *filp)
{
    #define DEVICE_MAX_PATH 20
    #define DEVICE_NUM 0
    char filename[DEVICE_MAX_PATH];

    /* REALIZA LA SINCRONIZACION ENTRE LOS PROCESOS */
    if(!(mutex_trylock(&xmutex)))
        return -EBUSY;

    snprintf(filename, DEVICE_MAX_PATH, "/dev/ttyACM%d", DEVICE_NUM);
    device = device_open(filename, 0, O_RDWR);
    if (PTR_RET(device)) {
        mutex_unlock(&xmutex);
        return PTR_RET(device);
    }

    return 0;
}
//Permite terminar con la utilizacion del dispositivo
static int dev_release(struct inode *inode, struct file *file)
{
    if(!IS_ERR_OR_NULL(device))
        dev_close(device, 0);
    mutex_unlock(&xmutex);
    return 0;
}

// Permite la escritura de un buffer en un puntero de memoria valido
static ssize_t dev_write(struct file *filp,
                 const char __user * buf, size_t count,
                 loff_t * f_pos)
{

    #define DEVICE_MAX_BUF_LEN 200
    const char kbuf[DEVICE_MAX_BUF_LEN];

    count = count < DEVICE_MAX_BUF_LEN ? count : DEVICE_MAX_BUF_LEN;
    if (copy_from_user((char *)kbuf, (const char __user *)buf, count))
        return -EFAULT;

    if (!IS_ERR_OR_NULL(device))
        return device_write(device, kbuf, count);
    else
        return -EFAULT;
}

// Estructura para el manejo de las operaciones
static struct file_operations dev_ops = {
    .owner = THIS_MODULE,
    .open = xdev_open,
    .release = dev_release,
    .write = dev_write,
};

/* =================== GENERACION DEL MODULO ======================== */

static struct cdev cdev;
static struct class *class;
static int dev_mjr;

static int dev_init(void)
{
    #define DEVICE_NAME "roboticArm"

    dev_t devt = MKDEV(0, 0);
    if (alloc_chrdev_region(&devt, 0, 1, DEVICE_NAME) < 0)
        return -1;
    dev_mjr = MAJOR(devt);

    cdev_init(&cdev, &dev_ops);
    cdev.owner = THIS_MODULE;
    devt = MKDEV(dev_mjr, 0);
    if (cdev_add(&cdev, devt, 1))
        goto exit0;

    class = class_create(THIS_MODULE, DEVICE_NAME);
    if (!class)
        goto exit1;

    devt = MKDEV(dev_mjr, 0);
    if (!(device_create(class, NULL, devt, NULL, DEVICE_NAME)))
        goto exit2;

    return 0;

exit2:
    class_destroy(class);
exit1:
    cdev_del(&cdev);
exit0:
    unregister_chrdev_region(MKDEV(dev_mjr, 0), 1);

    return -1;
}

static void dev_end(void)
{
    device_destroy(class, MKDEV(dev_mjr, 0));
    class_destroy(class);
    cdev_del(&cdev);
    unregister_chrdev_region(MKDEV(dev_mjr, 0), 1);
}

module_init(dev_init);
module_exit(dev_end);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("David Monestel - Jairo Mendez");