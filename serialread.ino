 #include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create an instance of the PCA9685 driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo settings
#define SERVOMIN 150  // Minimum pulse length count (approx 0°)
#define SERVOMAX 600  // Maximum pulse length count (approx 180°)

// Function to convert angle to pulse length

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
void servocom(int x, int y, int z){
  pwm.setPWM(x-1, 0, angleToPulse(45));
  pwm.setPWM(z-1, 0, angleToPulse(45));
  delay(y);
  pwm.setPWM(x-1, 0, angleToPulse(0));
  pwm.setPWM(z-1, 0, angleToPulse(0));
  }


void setup() {
  pwm.begin();
  pwm.setPWMFreq(50); // Set frequency to 50 Hz
Serial.begin(9600);
 
}

void loop() {

String myString= Serial.readString();
  // Extract a substring starting from index 0 to index 4 (5 characters)
 String subString1 = myString.substring(0, 2);
  Serial.println(subString1);  // Output: Hello

  // Extract a substring starting from index 7 to the end of the string
  
String subString2 = myString.substring(4,8);
  Serial.println(subString2);  // Output: Arduino!
  String subString3 = myString.substring(2, 4);
   Serial.println(subString3); 
int x;
int y;
int z;
x = subString1.toInt();
y = subString2.toInt();
z = subString3.toInt();
  // Extract a substring with a different range
 servocom(x,y,z);
}
