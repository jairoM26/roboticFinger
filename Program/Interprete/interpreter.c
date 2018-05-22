#include "interpreter.h"

void interpreter(){
    FILE * fp;    
    int param = 0;
    fp = fopen(configFile, "r");
    int linea = 1;
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
                if(param < 0 || param > 9){
                    printf("Error on line: %d, the key value must between 0 and 9\n", linea);
                    exit(0);
                }
                printf("moving to: %d\n", param);
                //arm_move(param);
            } else if(strcmp(key, "press") == 0){           //Read push option
                sscanf(value, "%d", &(param));
                if(param < 0){
                    printf("Error on line: %d, the seconds value must be positive\n", linea);
                    exit(0);
                }
                printf("pressing for: %d\n", param);
                //arm_push(param);
            } else if(strcmp(key, "touch\n") == 0){   //Read the SYNthreshold
                printf("touching");
               // arm_touch();
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