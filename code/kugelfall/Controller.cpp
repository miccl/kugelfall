#include "Controller.h"

Controller::Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk) : _ps(ps), _hs(hs), _servo(servo), _tg(tg), _disk(disk){

}


int Controller::getReleaseTime() {
  // TODO - implement Controller::getReleaseTime
  int delta_photo = _disk->getDelta();
  int t_hall = _disk->t_hall;
  int t_release = t_hall + 6*delta_photo - T_FALL;
  int eps = 10;
  while(t_release < millis() + eps) {
    t_release += 12 * delta_photo;
  }
  return t_release;
}

int Controller::getHoleDelay() {
  // TODO - implement Controller::getHoleDelay
}


void Controller::release() {
    _servo->open();
    delay(100);
    _servo->close();
}


void Controller::release(int releaseTime) {
  //weiß net mehr wie wir das wollten. ob jetzt wir jetzt nen delay nutzen wollten oder ne ständige abfrage
  while(millis()<=releaseTime) {
    
  }
  release();
}
