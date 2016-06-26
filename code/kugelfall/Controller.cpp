#include "Controller.h"

Controller::Controller(Servomotor* servo, Disk* disk) : _servo(servo), _disk(disk) {

  
}


long Controller::getReleaseTime() {
  long delta_photo = _disk->getDelta();
  #ifdef DEBUG
    Serial.print("Delta: ");
    Serial.println(_disk->getDelta(), DEC);
  #endif
  double magic_number = 0;
  long t_release = _disk->getHall() + 6*delta_photo - T_FALL + magic_number * delta_photo;
  while(t_release < (millis() + releaseEps)) {
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
  #ifdef DEBUG
    Serial.print("Release Time: ");
    Serial.println(releaseTime);
  #endif
  
  int eps = 300; //TODO noch anständig zu wählen
  long currentTime = millis();
  while(currentTime < releaseTime) {        
    //if(_trigger->getValue()) {
    //  increaseTriggerCount();
    //}
    //if((releaseTime - currentTime) > (eps + releaseEps)) {
    //   delay(eps);
    //    releaseTime = getReleaseTime(); //um die verlangsamung miteinzubeziehen
    //}
    currentTime = millis();
  }
  release();
}

void Controller::increaseTriggerCount() {
  count++;
  #ifdef DEBUG
  Serial.println(count, DEC);
  #endif
}

