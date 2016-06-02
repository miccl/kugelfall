#include "Controller.h"

Controller::Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk) : _ps(ps), _hs(hs), _servo(servo), _tg(tg), _disk(disk){

}

int Controller::getReleaseTime() {
  // TODO - implement Controller::getReleaseTime
  int speed = _disk->getSpeed();
}

int Controller::getHoleDelay() {
  // TODO - implement Controller::getHoleDelay
}


void Controller::release() {
    _servo->open();
    delay(100);
    _servo->close();
}

/**
 * Releases a ball at the given time.
 */
void Controller::release(int releaseTime) {
  //weiß net mehr wie wir das wollten. ob jetzt wir jetzt nen delay nutzen wollten oder nen pull
    int waitTime = releaseTime - millis();
    if(waitTime > 0) 
      delay(waitTime);
   release();
}
