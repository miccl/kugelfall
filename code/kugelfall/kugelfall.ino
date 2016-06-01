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
const int triggerPin = 4;
const int servoPin = 9;

const int LEDPin = 13;
const int button1Pin = 10;
int hallState;
int photoState;
bool pressed;

Sensor* hs;
Sensor* ps;
Servomotor* servo;
Disk* disk;
Sensor* tg;
Controller* controller;

void setup() {
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  tg = new Sensor(triggerPin);
  servo = new Servomotor(servoPin);
  disk = new Disk(ps);
  controller = new Controller(ps, hs, tg, servo, disk);


  Serial.begin(9600);           // set up Serial library at 9600 bps

}

void loop() {
  if(digitalRead(button1Pin)) {
    pressed = true;
  }
  
  if(tg->getValue()) {
    servo->open();
    delay(100);
    servo->close();
  }  
}

