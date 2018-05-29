#include <roboticArmLib.h>

/**
 * @brief 
 * 
 * @param deviceFile 
 * @return int 
 */
int dev_open(const char* deviceFile){
    
    struct termios options;
	int n, fd;
	fd =  open(deviceFile, O_WRONLY);
	
    if (fd == -1){
		perror("open_port: Unable to open fd");
	}
    return fd;
}
/**
 * @brief 
 * 
 * @param fd 
 * @return int 
 */
int dev_release(int fd){
    close(fd);
    return 1;
}

/**
 * @brief 
 * 
 * @param fd 
 * @param buffer 
 * @return int 
 */
int dev_write(int fd, char* buffer){
    //printf("command %s\n", buffer);
    int ret = write(fd, buffer, strlen(buffer));
    if (ret < 0)
    {
        perror("Failed to write the message to roboticArm.");
        return errno;
    }
    return 1;
}

/**
 * @brief 
 * 
 * @param fd 
 * @param buffer 
 * @return int 
 */
int dev_read(int fd, char* buffer){
    return 1;
}

/**
 * @brief Set the Resolution object
 * 
 * @param deviceName 
 * @param resolution 
 */
void setResolution(const char* deviceName,int resolution){
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else{
        if(resolution == 1) dev_write(fd, "3,61,150,95");
        else if(resolution == 2) dev_write(fd, "3,57,140,90");
        else if(resolution == 5) dev_write(fd, "3,57,140,90");
        else if(resolution == 4) dev_write(fd, "3,55,140,86");
    }
    
}

/**
 * @brief 
 * 
 * @param deviceName 
 * @param resolution 
 */
void arm_touch(const char* deviceName, int resolution){
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else{
		dev_write(fd, "0");
    }
}

/**
 * @brief 
 * 
 * @param deviceName 
 * @param pSeconds 
 * @param resolution 
 */
void arm_push(const char* deviceName, int pSeconds, int resolution)
{
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else{
		dev_write(fd, "1,3");
    }    
}

/**
 * @brief 
 * 
 * @param deviceName 
 * @param pNumber 
 * @param pResolution 
 */
void arm_move(const char* deviceName, int pNumber, int pResolution)
{
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else if (pNumber == 10) //ok
    {
        if(pResolution == 1) dev_write(fd, "2,60,105,80");
        else if(pResolution == 2) dev_write(fd, "2,57,99,70");
        else if(pResolution == 4) dev_write(fd, "2,55,98,64");
        else if(pResolution == 5) dev_write(fd, "2,57,99,70");
    }
    else if (pNumber == 0)//0
    {
        if(pResolution == 1) dev_write(fd, "2,65,105,80");
        else if(pResolution == 2) dev_write(fd, "2,63,99,70");
        else if(pResolution == 4) dev_write(fd, "2,64,98,62");
        else if(pResolution == 5) dev_write(fd, "2,63,99,70");
    }
    else if (pNumber == 1)//1
    {
        if(pResolution == 1) dev_write(fd, "2,64,102,88");
        else if(pResolution == 2) dev_write(fd, "2,62,98,78"); 
        else if(pResolution == 4) dev_write(fd, "2,62,98,72");
        else if(pResolution == 5) dev_write(fd, "2,63,99,70");
    }
    else if (pNumber == 2)//2
    {
        if(pResolution == 1) dev_write(fd, "2,60,102,88");
        else if(pResolution == 2) dev_write(fd, "2,57,98,78");
        else if(pResolution == 4) dev_write(fd, "2,55,98,74");
        else if(pResolution == 5) dev_write(fd, "2,57,98,78");
    }
    else if (pNumber == 3)//3
    {
        if(pResolution == 1) dev_write(fd, "2,56,102,88"); 
        else if(pResolution == 2) dev_write(fd, "2,50,98,78"); 
        else if(pResolution == 4) dev_write(fd, "2,45,98,75"); 
        else if(pResolution == 5) dev_write(fd, "2,50,98,78"); 
    }
    else if (pNumber == 4)//4
    {
        if(pResolution == 1) dev_write(fd, "2,64,102,95");
        else if(pResolution == 2) dev_write(fd, "2,62,101,87");
        else if(pResolution == 4) dev_write(fd, "2,62,101,87");
        else if(pResolution == 5) dev_write(fd, "2,62,101,87");
    }
    else if (pNumber == 5)//5
    {
        if(pResolution == 1) dev_write(fd, "2,59,102,95");
        else if(pResolution == 2) dev_write(fd, "2,56,101,87"); 
        else if(pResolution == 4) dev_write(fd, "2,55,98,86");
        else if(pResolution == 5) dev_write(fd, "2,58,101,87"); 
    }
    else if (pNumber == 6)
    {
        if(pResolution == 1) dev_write(fd, "2,56,102,95");
        else if(pResolution == 2) dev_write(fd, "2,50,101,89");
        else if(pResolution == 4) dev_write(fd, "2,47,99,89");
        else if(pResolution == 5) dev_write(fd, "2,50,101,89");
    }
    else if (pNumber == 7)//7
    {
        if(pResolution == 1) dev_write(fd, "2,64,105,102");
        else if(pResolution == 2) dev_write(fd, "2,62,103,100");
        else if(pResolution == 4) dev_write(fd, "2,62,101,100");
        else if(pResolution == 5) dev_write(fd, "2,62,103,94");
    }
    else if (pNumber == 8)//8
    {
        if(pResolution == 1) dev_write(fd, "2,60,105,102");
        else if(pResolution == 2) dev_write(fd, "2,56,105,100");
        else if(pResolution == 4) dev_write(fd, "2,55,101,100");
        else if(pResolution == 5) dev_write(fd, "2,56,105,94");
    }
    else if (pNumber == 9)//9
    {
        if(pResolution == 1) dev_write(fd, "2,56,107,102");
        else if(pResolution == 2) dev_write(fd, "2,50,105,100");
        else if(pResolution == 5) dev_write(fd, "2,50,105,94");
        else if(pResolution == 4) dev_write(fd, "2,47,101,100");
    }
}













