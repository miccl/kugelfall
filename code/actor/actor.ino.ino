/**
 * 
 */

#include <Servo.h>

const int triggerPin = 4;
const int servoPin = 9;

const int endPos = 20;
const int startPos = 0;

int pos = 0;    // variable to store the servo position´
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  myservo.write(startPos);

  pinMode(triggerPin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  if (digitalRead(triggerPin)) {
    myservo.write(endPos);
    delay(100);
    myservo.write(startPos);
  }
}
