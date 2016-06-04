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
}

void photoISR() {
  //TODO müssen hier aufpassen, dass die geschwindigkeit auf falschen werten gelesen wird. also wenn disk getSpeed macht liest er die werte aus. wurden die aber noch nicht von dem hier aktualisiert, wäre das fatal. 
  //dumme alternative wäre, wir lassen das hier die ganze zeit laufen.
  if (activated) { //if the trigger was pressed
      if (photoStateFlank) { 
        disk->t_low = millis();
        photoStateFlank = true;
      }
      else {
        disk->t_low = millis();
        photoStateFlank = false;
      }
  }

}

void hallISR() {
  if(activated) {
    //TODO siehe oben. vielleicht hier nen delay einbauen, der auch abhängig von der scheibengeschwindigkeit ist.
    double t_rel = controller->getReleaseTime(millis()); //TODO wir müssen mit den Einheiten aufpassen,
    controller->release(t_rel);
    count--;
    if(count==0) {
      activated = false;
    }
    delay(1000); //delay, damit nicht hintereinander gleich zwei Kugeln losgelassen werden
  }
}

void triggerISR() {
  count++;
  activated = true;
}

