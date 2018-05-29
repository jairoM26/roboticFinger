#include "interpreter.h"

/**
 * @brief Method that do the job of an interpreter
 * 
 * @description This method read line per line a configuration file
 *              and verify the function that is indicated into that file, 
 *              if the function doesnt exist or the format is not ok, an 
 *              error would be display, otherwise, the program will interact...
 *              with the library which talks with the linux driver module for the COM
 */
void interpreter(){
    FILE * fp;    
    int param = 0;
    fp = fopen(configFile, "r"); //open the file
    int linea = 1;
    if (fp == NULL){
        fclose(fp); 
        exit(EXIT_FAILURE);
    }
    else{
        char key[256], value[256];
        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, fp)) != -1) { //read line per line
           sscanf(line, "%s %s", key, value); //get keys and values
           if(strcmp(key, "resolution") == 0){             //reading resolution                
                sscanf(value, "%d", &(resolution));             
                printf("setting resolution %d\n", resolution);//setting resolution
                setResolution(deviceName, resolution); //call library for setting resolution into the device
                usleep(3000000);
            } else if(strcmp(key, "move") == 0){           //Read move option                
                sscanf(value, "%d", &(param));
                if(param < 0 || param > 10){    //compare entries values
                    printf("Error on line: %d, the key value must between 0 and 9\n", linea);
                    exit(0);
                }
                printf("moving to: %d\n", param);
                arm_move(deviceName,param, resolution); //call library to tell the driver to move
                usleep(3000000);
            } else if(strcmp(key, "press") == 0){           //Read push option
                sscanf(value, "%d", &(param));
                if(param < 0){
                    printf("Error on line: %d, the seconds value must be positive\n", linea);
                    exit(0);
                }
                printf("pressing for: %d\n", param);
                arm_push(deviceName,param,resolution); //press for an amount of time
                usleep(param*100000+3000000);
                //usleep(3000000);
            } else if(strcmp(key, "touch") == 0){   //Read the SYNthreshold
                printf("touching\n");
                arm_touch(deviceName, resolution);
        
                usleep(3000000);
            } else{
                if(strcmp(key, "") != 0){
                    printf("Error on line: %d, instruction %s not exist\n", linea, key);
                    exit(0);
                }                
            }
            linea++;
            memset(key, 0, sizeof key);
        }
        fclose(fp);    
    }
}

int main (int argc, char *argv[] ){
    if(strcmp(argv[1], "-g") == 0){
        if(argc < 3){
            printf("Error, config file not provided \n");
            exit(0);
        }
        configFile = argv[2];
        printf("using GUI %s\n", configFile);  
        interpreter();     
    }
    else if(strcmp(argv[1], "-c") == 0){
        if(argc < 3){
            printf("Error, config file not provided \n");
            exit(0);
        }
        configFile = argv[2];
        printf("Using the config file: %s\n", configFile);
        interpreter();
    }   

}