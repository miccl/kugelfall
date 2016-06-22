/**
 * 
 */

#include "Sensor.h"
#include "Actor.h"
#include "Servomotor.h"
#include "Disk.h"
#include "Controller.h"

//#define DEBUG 1

// sensors
const int photoPin = 2;
const int hallPin = 3;
const int triggerPin = 4;
const int servoPin = 9;


//actors
const int button1Pin = 10;
const int LED1Pin = 12;
const int LED2Pin = 13;

bool isPhotoHigh = false;

Sensor* hs;
Sensor* ps;
Sensor* tg;
Servomotor* servo;
Actor* led1;
Actor* led2;
Disk* disk;
Controller* controller;
Sensor* button1;

void setup() {
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  tg = new Sensor(triggerPin);
  led1 = new Actor(LED1Pin);
  led2 = new Actor(LED2Pin);
  button1 = new Sensor(button1Pin);
  servo = new Servomotor(servoPin);
  disk = new Disk();
  controller = new Controller(servo, disk, tg);

  attachInterrupt(digitalPinToInterrupt(ps->getPin()), photoISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(hs->getPin()), hallISR, RISING);
  #ifdef DEBUG 
  Serial.begin(9600);           // set up Serial library at 9600 bps
  #endif
}

void loop() {
  if(!button1->getValue()) {
    if(tg->getValue()) {
      controller->increaseTriggerCount();
    }
    disk->getDelta(); 
    if(!disk->stopped){ // disk is stopping
      led1->setValue(false);
      if (controller->count > 0) {
        long t_release = controller->getReleaseTime();
        controller->release(t_release);
        controller->count--;
      }
    } else {
      led1->setValue(true);
    }
  }
  
}

void photoISR() {
  if(isPhotoHigh) {
    disk->setPhotoHigh(millis());
    isPhotoHigh = false;
  }
  else {
    disk->setPhotoLow(millis());
    isPhotoHigh = true;
  }
}

void hallISR() {
  disk->setHall(millis());
}

