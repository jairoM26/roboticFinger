#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#ifndef ROBOTICARMLIB
#define ROBOTICARMLIB 

int dev_open(const char* deviceFile);
int dev_release(int fd);
int dev_write(int fd, char* buffer);
int dev_read(int fd, char* buffer);

#endif