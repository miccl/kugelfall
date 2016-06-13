#include "Controller.h"

Controller::Controller(Servomotor* servo, Disk* disk) : _servo(servo), _disk(disk){

}


long Controller::getReleaseTime() {
  // TODO - implement Controller::getReleaseTime
  long delta_photo = _disk->getDelta();
  Serial.println(delta_photo);
  long t_hall = _disk->t_hall;
  Serial.println(t_hall);
  long t_release = t_hall + 6*delta_photo - T_FALL;
  int eps = 100; //10 oder 100
  while(t_release < millis() + eps) {
    t_release += 12 * delta_photo;
  }
  return t_release;
}

void Controller::release() {
    _servo->open();
    delay(100);
    _servo->close();
}


void Controller::release(long releaseTime) {
  //Serial.print("Release Time: ");
  //Serial.println(releaseTime);
  //weiß net mehr wie wir das wollten. ob jetzt wir jetzt nen delay nutzen wollten oder ne ständige abfrage
  int eps = 100;
  while(millis()<=releaseTime) {
    //if(releaseTime - millis() > eps) {
    //    releaseTime = getReleaseTime(); //um die verlangsamung miteinzubeziehen
    //}
  }
  release();
  //Serial.println("Gooo");
}
