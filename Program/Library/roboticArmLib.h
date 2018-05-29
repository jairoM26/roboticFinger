#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#ifndef ROBOTICARMLIB
#define ROBOTICARMLIB 

/**
 * @brief 
 * 
 * @param deviceFile 
 * @return int 
 */
int dev_open(const char* deviceFile);

/**
 * @brief 
 * 
 * @param fd 
 * @return int 
 */
int dev_release(int fd);

/**
 * @brief 
 * 
 * @param fd 
 * @param buffer 
 * @return int 
 */
int dev_write(int fd, char* buffer);

/**
 * @brief 
 * 
 * @param fd 
 * @param buffer 
 * @return int 
 */
int dev_read(int fd, char* buffer);

/**
 * @brief 
 * 
 * @param deviceName 
 */
void arm_touch(const char* deviceName,int pResolution);

/**
 * @brief 
 * 
 * @param deviceName 
 * @param pSeconds 
 */
void arm_push(const char* deviceName, int pSeconds,int pResolution);

/**
 * @brief 
 * 
 * @param deviceName 
 * @param pNumber 
 * @param pResolution 
 */
void arm_move(const char* deviceName,int pNumber,int pResolution);

/**
 * @brief 
 * 
 */
void setResolution(const char* deviceName, int resolution);

#endif