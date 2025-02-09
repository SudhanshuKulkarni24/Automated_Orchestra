
#include <Servo.h>
Servo kservo[19];
void servocom(int x, int y, int lor,float del ){
 int ang = (x>11)?(lor==1?70:110):(lor==0?30:150);
 //int ang = 30;
 //if(lor == 1)
   // ang = 150;
 //else
  //ang = 15;
 if(y==1)
 kservo[x-1].write(ang);
 else
 kservo[x-1].write(90); 
 delay((int)del*1000);
  }  
  

void setup() {

  Serial.begin(9600);
int pin = 23;
int servonum=0;
while(servonum<=18){
  if(servonum==11)
  pin = 3;
  kservo[servonum].attach(pin);
  kservo[servonum].write(90);
  delay(100);
  servonum++;
  pin++;
}
}


void loop() {
  String myString;
 if(Serial.available()>0){
  myString= Serial.readStringUntil('\n');
  
  Serial.println(myString); 
 // Serial.flush();}
//string format  is servonumber|servonumber|delay|1 for ACW and 0 for CW   eg. 0110001
//format for servo numbers, is 01 for first servo of first driver and 11 for first servo of second driver,
//for using only one servo at a time give 00.
  
 String subString1 = myString.substring(0, 2);
  //Serial.println(subString1);  
 String subString2 = myString.substring(2,3);
  //Serial.println(subString2);  
 String subString4 = myString.substring(3, 4);
   //Serial.println(subString4); 
  String subString5 = myString.substring(4,9);
 
int x;
int y;
int lor;
float del = subString5.toFloat();
x = subString1.toInt(); // servo1
y = subString2.toInt(); // delay
lor = subString4.toInt(); //cw or acw
servocom(x,y,lor,del);
 }
}
