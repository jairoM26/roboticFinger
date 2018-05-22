#include <stdio.h>
#include <stdlib.h>
#include "../Library/roboticArmLib.h"

const char * deviceName = "/dev/ttyACM0";
char * configFile = "configFile.txt";
int resolution = 1;

int posInitX = 50;
int posInitY = 50;

/**
 * @brief 
 * 
 */
void arm_touch();

/**
 * @brief 
 * 
 * @param pSeconds 
 * @return int 
 */
void arm_push(int pSeconds);

/**
 * @brief 
 * 
 * @param pNumber 
 * @return int 
 */
void arm_move(int pNumber);

/**
 * @brief 
 * 
 */
void returnInitialPos();

/**
 * @brief 
 * 
 */
void interpreter();