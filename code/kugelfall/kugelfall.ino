/**
 * 
 */

#include "Sensor.h"
#include "Actor.h"
#include "Servomotor.h"
#include "Disk.h"
#include "Controller.h"


// sensors
const int photoPin = 2;
const int hallPin = 3;
const int triggerPin = 4;
const int servoPin = 9;
const int LEDPin = 13;

//actors
const int button1Pin = 10;

bool isPhotoHigh = false;

Sensor* hs;
Sensor* ps;
Sensor* tg;
Servomotor* servo;
Actor* led;
Disk* disk;
Controller* controller;

void setup() {
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  tg = new Sensor(triggerPin);
  led = new Actor(LEDPin);
  servo = new Servomotor(servoPin);
  disk = new Disk();
  controller = new Controller(servo, disk, tg);

  
  attachInterrupt(digitalPinToInterrupt(ps->getPin()), photoISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(hs->getPin()), hallISR, RISING);

  Serial.begin(9600);           // set up Serial library at 9600 bps

}

void loop() {
  if(tg->getValue()) {
    controller->increaseTriggerCount();
  }
  Serial.println(disk->getDelta(), DEC); 
  
  if (controller->count > 0) {
    long t_release = controller->getReleaseTime();
    controller->release(t_release);
    controller->count--;
  }
  
}

void photoISR() {
  if(isPhotoHigh) {
    disk->t_photo_high = millis();
    isPhotoHigh = false;
  }
  else {
    disk->t_photo_low = millis();
    isPhotoHigh = true;
  }
}

void hallISR() {
  disk->t_hall = millis();
  led->setValue(true);
  delay(100);
  led->setValue(false);
}



