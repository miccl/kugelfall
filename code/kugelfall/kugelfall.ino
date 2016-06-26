/**
 * kugelfall.ino
 * Main class of the project.
 */

#include "Sensor.h"
#include "Actor.h"
#include "Servomotor.h"
#include "Disk.h"
#include "Controller.h"

//#define DEBUG 1

// sensors
/**
 * Arduino input pin of photosensor.
 */
const int photoPin = 2;
/**
 * Arduino input pin of hallsensor.
 */
const int hallPin = 3;
/**
 * Arduino input pin of trigger.
 */
const int triggerPin = 4;
/**
 * Arduino input pin of button1.
 */
const int button1Pin = 10;

//actors
/**
 * Arduino ouput pin of servomotor.
 */
const int servoPin = 9;

/**
 * Arduino output pin of LED1.
 */
const int LED1Pin = 12;
/**
 * Arduino output pin of LED1.
 */
const int LED2Pin = 13;

/**
 * Wether the last interrupt was falling or rising flank.
 */
bool isPhotoHigh = false;

/**
 * Pointer to the sensor instance.
 */
Sensor* hs;
/**
 * Pointer to the sensor instance.
 */
Sensor* ps;
/**
 * Pointer to the sensor instance.
 */
Sensor* tg;
/**
 * Pointer to the sensor instance.
 */
Servomotor* servo;
/**
 * Pointer to the actor instance.
 */
Actor* led1;
/**
 * Pointer to the actor instance.
 */
Actor* led2;
/**
 * Pointer to the disk instance.
 */
Disk* disk;
/**
 * Pointer to the controller instance.
 */
Controller* controller;
/**
 * Pointer to the sensor instance.
 */
Sensor* button1;

/**
 * Setups the Arduino programm. 
 * Invoked once.
 * 
 * Class instances get created and initialised.
 * Interupt routines and serial port get settled.
 */
void setup() {
  disk = new Disk();
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  tg = new Sensor(triggerPin);
  led1 = new Actor(LED1Pin);
  led2 = new Actor(LED2Pin);
  button1 = new Sensor(button1Pin);
  servo = new Servomotor(servoPin);
  controller = new Controller(servo, disk);

  attachInterrupt(digitalPinToInterrupt(ps->getPin()), photoISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(hs->getPin()), hallISR, RISING);
  #ifdef DEBUG 
  Serial.begin(9600);           // set up Serial library at 9600 bps
  #endif
}

/**
 * Main loop of the Arduino program.
 * 
 * Tests if the user pressed the trigger.
 * If so, it starts the release process by invoking the controller.
 */
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

/**
 * Interrupt routine function for the photosensor.
 * Called when the sensor detects a falling and rising flank.
 */
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

/**
 * Interrupt routing function for the hallsensor.
 * Called when the sensor detects a rising flank.
 */
void hallISR() {
  disk->setHall(millis());
}

