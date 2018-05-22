#include <roboticArmLib.h>

int dev_open(const char* deviceFile){
    
    struct termios options;
	int n, fd;
	fd = open(deviceFile, O_RDWR | O_NOCTTY );
	tcgetattr(fd, &options);
	cfsetispeed(&options, B115200);
	cfsetospeed(&options, B115200);
	
    options.c_cflag |= (CLOCAL | CREAD);
	tcsetattr(fd, TCSANOW, &options);
	
    if (fd == -1){
		perror("open_port: Unable to open fd");
	}
	
    return fd;
}
int dev_release(int fd){
    close(fd);
    return 1;
}
int dev_write(int fd, char* buffer){
    //int n;
    char* arg = (char*) malloc(sizeof(char)*50); 
    strcpy(arg, "echo ");
    strcat(arg, buffer);
    strcat(arg," > /dev/roboticArm");
    //n = write(fd, buffer,50);
    //printf(arg);
    system(arg);
    usleep(100);
    return 1;
}
int dev_read(int fd, char* buffer){
    return 1;
}


void arm_touch(const char* deviceName){
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else{
		dev_write(fd, "20");
		usleep(3);
    }
}

void arm_push(const char* deviceName, int pSeconds)
{
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else{
		dev_write(fd, "3");
		usleep(3);
    }    
}


void arm_move(const char* deviceName, int pNumber, int pResolution)
{
    int fd = dev_open(deviceName);
	if (fd<0){
        exit(EXIT_FAILURE);
	}
    else if (pNumber == 0)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50"); 
		usleep(3);
    }
    else if (pNumber == 1)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 2)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 3)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 4)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 5)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 6)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 7)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 8)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
    else if (pNumber == 9)
    {
        dev_write(fd, "50,50"); // Return initial Position
        dev_write(fd, "50,50");
		usleep(3);
    }
}

void returnInitialPos(const char* deviceName){
	int fd = dev_open(deviceName);
	if (fd<0){
		return;
	}
	dev_write(fd, "50,50,50");
	sleep(2);
}












