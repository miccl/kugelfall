#include "Controller.h"

Controller::Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk) : _ps(ps), _hs(hs), _servo(servo), _tg(tg), _disk(disk){

}

int Controller::getReleaseTime(long t_loch) {
  // TODO - implement Controller::getReleaseTime
  double speed = _disk->getSpeed();
  double t_0 = t_loch + S_FALL/speed - T_FALL;
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
  //weiß net mehr wie wir das wollten. ob jetzt wir jetzt nen delay nutzen wollten oder ne ständige abfrage
  while(millis()<=releaseTime) {
    
  }
//    int waitTime = releaseTime - millis();
//    if(waitTime > 0) 
//      delay(waitTime);
   release();
}
