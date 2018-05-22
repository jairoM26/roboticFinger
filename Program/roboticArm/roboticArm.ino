#include <Servo.h>

int pinServoCuerpo = 9;
int pinServoIzqEst = 2;
int pinServoDerVert = 11;


bool flag = true;

int countY = 0;
Servo servoCuerpo;
Servo servoIzqEst;
Servo servoDerVert;

String data = "";

int pos = 0; 
int angleArm = 0;
int anglePush = 0;

void setup() {

  Serial.begin(115200);
  servoCuerpo.attach(pinServoCuerpo);
  servoIzqEst.attach(pinServoIzqEst);
  servoDerVert.attach(pinServoDerVert);  
  
}

int n1, n2, n3;

void loop() {     
    
    if (Serial.available()) {
      //char inChar = (char)Serial.read();
      data = Serial.readString();
      Serial.print(data); 
      if (data.charAt(0) == 'a'){
                
         servoIzqEst.write(130);
         delay(5000);
        
         
         //servoIzqEst.write(60);
         //delay(3000);
      }

      if (data.charAt(0) ==  's'){
                
         servoIzqEst.write(60);
         delay(5000);
         //servoIzqEst.write(0);
         //delay(3000);
      }         
    }    
    /*servoIzqEst.write(130);
    delay(8000);
    servoIzqEst.write(30);
    delay(8000);*/
}
