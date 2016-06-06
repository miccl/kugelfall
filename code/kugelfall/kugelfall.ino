/**
 * sensor value capturing
 * gets the sensor values and write them into a file.
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

int hallState;
int photoState;
bool photoStateFlank;
bool pressed;
int count;
bool activated;

Sensor* hs;
Sensor* ps;
Servomotor* servo;
Actor* led;
Disk* disk;
Sensor* tg;
Controller* controller;

void setup() {
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  tg = new Sensor(triggerPin);
  led = new Actor(LEDPin);
  servo = new Servomotor(servoPin);
  disk = new Disk(ps);
  controller = new Controller(ps, hs, tg, servo, disk);
  
  attachInterrupt(digitalPinToInterrupt(ps->getPin()), photoRisingISR, RISING);
  attachInterrupt(digitalPinToInterrupt(ps->getPin()), photoFallingISR, FALLING);
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

  if (count > 0) {
    int t_release = controller->getReleaseTime();
    controller->release(t_release);
    count--;
    
  }
  
}

void photoRisingISR() {
  disk->t_low = millis();
}

void photoFallingISR() {
  disk->t_high = millis();
}

void hallISR() {
  disk->t_hall = millis();
  led->setValue(true);
  delay(100);
  led->setValue(false);
}

void triggerISR() {
  count++;
}



