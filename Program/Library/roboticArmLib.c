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












