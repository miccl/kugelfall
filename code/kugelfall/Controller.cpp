#include "Controller.h"

Controller::Controller(Servomotor* servo, Disk* disk) : _servo(servo), _disk(disk) {

  
}


long Controller::getReleaseTime() {
  long delta_photo = _disk->getDelta();
  #ifdef DEBUG
    Serial.print("Delta: ");
    Serial.println(delta_photo, DEC);
  #endif
  long releaseTime = _disk->getHall() + 6*delta_photo - (T_FALL + getDynamicDelay(delta_photo));
  long currentTime = millis();
  while(releaseTime < currentTime) {
    releaseTime += 12 * delta_photo - 6;
  }
  return releaseTime;
}

long Controller::getDynamicDelay(long delta) {
  if(delta >= 0 && delta <25) {
    return 0;
  } else if (delta >=25 && delta <50) {
    return ((0.2 * delta) - 5); 
  } else if (delta >= 50 && delta <150) {
    return ((0.06 * delta) + 5);
  } else { //>150
    return 15;
  }
}
void Controller::release() {
    _servo->open();
    delay(100);
    _servo->close();
}


void Controller::waitForRelease() { 
  int eps = 5;
  
  while(true) {        
    if(!_disk->isSteady()) { //wenn sie gestoppt wird, dann soll nichts getan werden
      delay(100);
      continue;
    }
    
    //Neuberechnung der Zeit
    long releaseTime = getReleaseTime();
    long currentTime = millis();
    
    //long diff = releaseTime - currentTime;
    //Serial.println(diff, DEC);
    if((releaseTime - currentTime) > 200) {
      //delay(150);
      continue;
    }

    while(releaseTime >= currentTime) {
      currentTime = millis();
    }
    release();
    break;
  }
  //delay(1000); //gegen fehler von loslassen, direkt nachdem eine andere kugel losgelassen wurde
}

