#include "Controller.h"

Controller::Controller(Servomotor* servo, Disk* disk) : _servo(servo), _disk(disk) {

  
}


long Controller::getReleaseTime() {
  long delta_photo = _disk->getDelta();
  #ifdef DEBUG
    Serial.print("Delta: ");
    Serial.println(delta_photo, DEC);
  #endif
  double magic_number = 0;
  long releaseTime = _disk->getHall() + 6*delta_photo - T_FALL + magic_number * delta_photo;
  long currentTime = millis();
  while(releaseTime < currentTime) {
    releaseTime += 12 * delta_photo;
  }
  return releaseTime;
}

void Controller::release() {
    _servo->open();
    delay(100);
    _servo->close();
}


void Controller::release(long releaseTime) {
  //TODO nen bissel unlogisch hier releaseTime zu übergeben, wenn wir es eh gleich wieder überschreiben. hab es aber erstmal drin gelassen.
  #ifdef DEBUG
    Serial.print("Release Time: ");
    Serial.println(releaseTime);
  #endif
  
  int eps = 5; //TODO noch anständig zu wählen. hängt mit der Zeit, die für die Berechnung und millis() benötigt wird zusammen.
               //TODO das problem. das wir mit releaseEps lösen wollten. ist das noch vorhanden?! übernimmt das "eps" diese rolle?
  while(true) {        
    if(_disk->stopped) { //wenn sie gestoppt wird, dann soll nichts getan werden
      delay(10);
      continue;
    }

    //Neuberechnugn der Zeit
    releaseTime = getReleaseTime();
    long currentTime = millis();

    //TODO nochmal das darunter überlegen. wenn man genau darauf testet, funktioniert das nicht. deswegen diese range.
    //     aber vielleicht geht das schlauer. vielleicht ohne "-eps". im prinzip macht es bestimmt eh net son nen großen unterschied. :D
    if(currentTime >= releaseTime - eps && currentTime <= releaseTime + eps) {
      release();
      break;
    }
  }

    long currentTime = millis();
  
  while(currentTime >= releaseTime - eps && currentTime <= releaseTime + eps) {        
    while (_disk->stopped) { //wenn sie gestoppt wird, dann soll nichts getan werden
      delay(10);
    }

    //Neuberechnugn der Zeit
    releaseTime = getReleaseTime();
    currentTime = millis();
  }
}

