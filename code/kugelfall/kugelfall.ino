/**
 * sensor value capturing
 * gets the sensor values and write them into a file.
 */

#include "Sensor.h"
#include "Servomotor.h"
#include "Disk.h"
#include "Controller.h"
#include "Trigger.h"

// sensors
const int photoPin = 2;
const int hallPin = 3;
const int LEDPin = 13;
const int button1Pin = 10;
int hallState;
int photoState;
bool pressed;

Sensor* hs;
Sensor* ps;
Servomotor* servo;
Disk* disk;

void setup() {
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  Serial.begin(9600);           // set up Serial library at 9600 bps

}

void loop() {
  if(digitalRead(button1Pin)) {
    pressed = true;
  }
  
  if(!pressed) {
    long time = millis();
    bool hallState = hs->getValue();
    bool photoState = ps->getValue();
    Serial.print(time);
    Serial.print(",");
    Serial.print(hallState, DEC);
    Serial.print(",");
    Serial.print(photoState, DEC);
    Serial.println();
    digitalWrite(LEDPin, hallState);
  }  
  delay(10);
}
