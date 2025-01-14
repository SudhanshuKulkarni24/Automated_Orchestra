#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create an instance of the PCA9685 driver
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

// Servo settings
#define SERVOMIN 150  // Minimum pulse length count (approx 0°)
#define SERVOMAX 600  // Maximum pulse length count (approx 180°)

// Function to convert angle to pulse length

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
void servocom(int x, int y, int z, int lor){
  int ang = lor==0?45:135;
  if(x>10)
   pwm2.setPWM(x-11, 0, angleToPulse(ang));
 else
  pwm1.setPWM(x-1, 0, angleToPulse(ang));
  if(z>10)
  pwm2.setPWM(z-11, 0, angleToPulse(ang));
  else
   pwm1.setPWM(z-1, 0, angleToPulse(ang));
  delay(y);
   if(x>10)
   pwm2.setPWM(x-11, 0, angleToPulse(90));
 else
  pwm1.setPWM(x-1, 0, angleToPulse(90));
  if(z>10)
  pwm2.setPWM(z-11, 0, angleToPulse(90));
  else
   pwm1.setPWM(z-1, 0, angleToPulse(90));
  }


void setup() {
  int k = 8;
  pwm1.begin();
  pwm1.setPWMFreq(50); 
  pwm2.begin();
  pwm2.setPWMFreq(50); // Set frequency to 50 Hz

Serial.begin(9600);
while(k>=0){  // to bring all servos to normal position at the very start
   pwm1.setPWM(k, 0, angleToPulse(90));
    pwm2.setPWM(k, 0, angleToPulse(90));
    k--;
}
 
}

void loop() {

String myString= Serial.readString();
//string format  is servonumber|servonumber|delay|1 for ACW and 0 for CW   eg. 011210001
//format for servo numbers, is 01 for first servo of first driver and 11 for first servo of second driver,
//for using only one servo at a time give 00.
  
 String subString1 = myString.substring(0, 2);
  Serial.println(subString1);  
 String subString3 = myString.substring(2, 4);
   Serial.println(subString3); 
 String subString2 = myString.substring(4,8);
  Serial.println(subString2);  
 String subString4 = myString.substring(8, 9);
   Serial.println(subString4); 
int x;
int y;
int z;
int lor;
x = subString1.toInt(); // servo1
y = subString2.toInt(); // delay
z = subString3.toInt(); // servo2
lor = subString4.toInt(); //cw or acw
servocom(x,y,z,lor);
}
