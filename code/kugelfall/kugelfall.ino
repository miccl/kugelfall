/**
 * sensor value capturing
 * gets the sensor values and write them into a file.
 */

#include "Sensor.h"
#include "Servomotor.h"
#include "Disk.h"
#include "Controller.h"

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
int count;

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
  
  attachInterrupt(digitalPinToInterrupt(ps->getPin()), photoISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(hs->getPin()), hallISR, RISING);
  attachInterrupt(digitalPinToInterrupt(tg->getPin()), triggerISR, RISING);

  Serial.begin(9600);           // set up Serial library at 9600 bps

}

void loop() {
  if(digitalRead(button1Pin)) {
    pressed = true;
  }
  
  if(tg->getValue()) {
    controller->release();
  }  

  if(count>0) {
    int t_rel = controller->getReleaseTime();
    controller->release(t_rel);
    count--;
    delay(1000); //delay, damit nicht hintereinander gleich zwei Kugeln losgelassen werden
  }
}

void photoISR() {
  
}

void hallISR() {

}

void triggerISR() {
//  count++;
}

