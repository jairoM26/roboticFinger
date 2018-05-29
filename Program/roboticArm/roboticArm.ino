#include <Servo.h>

int pinServoIzqEst = 10;
int pinServoCuerpo = 11;
int pinServoDerVert = 9;


bool flag = true;

int countY = 0;
Servo servoCuerpo; //x
Servo servoIzqEst; //y
Servo servoDerVert; //z

String data = "";

int pSpeed = 250;
int tSpeed = 300;
int init_x = 56;
int init_y = 140;
int init_z = 90;

void setup() {

  Serial.begin(115200);
  servoCuerpo.attach(pinServoCuerpo);
  servoIzqEst.attach(pinServoIzqEst);
  servoDerVert.attach(pinServoDerVert);  
  servoCuerpo.write(init_x);
  servoIzqEst.write(init_y);
  servoDerVert.write(init_z);
  delay(3000);
  
}

void setRes(int x, int y, int z){
  int init_x = x;
  int init_z = z;
  servoCuerpo.write(x);
  delay(pSpeed); 
  servoDerVert.write(z);   
  delay(pSpeed);
}

void movePos(int x, int y, int z){
  servoCuerpo.write(x);
  delay(pSpeed); 
  servoDerVert.write(z);   
  delay(pSpeed);
  servoIzqEst.write(y);
  delay(pSpeed);
  servoIzqEst.write(init_y);
  delay(pSpeed);
  servoDerVert.write(init_z);   
  delay(pSpeed);
  servoCuerpo.write(init_x);
  delay(pSpeed);
}

void touch(){
  servoIzqEst.write(init_y-25);
  delay(tSpeed);
  servoIzqEst.write(init_y);
}

void pressed(int seconds){
  servoIzqEst.write(105);
  delay(seconds*1000);
  servoIzqEst.write(init_y);
}

void loop() {
   
  if (Serial.available()) {
    //char inChar = (char)Serial.read();
    data = Serial.readString();
    Serial.print(data);
    Serial.print("\n");
    // Convert from String Object to String.
    char buf[data.length()+1];
    data.toCharArray(buf, sizeof(buf));
    char *p = buf;
    char *str;
    int data[4];
    int cont = 0;
    while ((str = strtok_r(p, ",", &p)) != NULL){ // delimiter is the semicolon
      data[cont] = atoi(str);
      cont++;
    }
    if(data[0] == 0){ //for touch
      touch();
    }
    else if(data[0] == 1){ //for press
      pressed(data[1]);
    }
    else if(data[0] == 2){ //for moving
      movePos(data[1], data[2], data[3]);
    }
    else if(data[0] == 3){ //for setting resolution
      setRes(data[1], data[2], data[3]);
    }       
  }
}
