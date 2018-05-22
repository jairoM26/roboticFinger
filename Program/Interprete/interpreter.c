#include "interpreter.h"

void interpreter(){
    FILE * fp;    
    int param = 0;
    fp = fopen(configFile, "r");
    if (fp == NULL){
        fclose(fp); 
        exit(EXIT_FAILURE);
    }
    else{
        printf("file open\n");
        char key[256], value[256];
        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, fp)) != -1) {
           sscanf(line, "%s %s", key, value);
           if(strcmp(key, "resolution") == 0){             //setting resolution
                printf("setting resolution %d\n", resolution);
                sscanf(value, "%d", &(resolution));
            } else if(strcmp(key, "move") == 0){           //Read move option                
                sscanf(value, "%d", &(param));
                printf("moving to: %d\n", param);
                //arm_move(param);
            } else if(strcmp(key, "press") == 0){           //Read push option
                sscanf(value, "%d", &(param));
                printf("pressing for: %d\n", param);
                //arm_push(param);
            } else if(strcmp(key, "touch\n") == 0){   //Read the SYNthreshold
                printf("touching");
               // arm_touch();
            }
            memset(key, 0, sizeof key);
        }
        fclose(fp);    
    }
}

int main (int argc, char *argv[] ){

    if(strcmp(argv[1], "-g") == 0){
        configFile = argv[2];
        printf("using GUI %s\n", configFile);  
        interpreter();     
    }
    else if(strcmp(argv[1], "-c") == 0){
        configFile = argv[2];
        printf("Using the config file: %s\n", configFile);
        interpreter();
    }   
}