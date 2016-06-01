#pragma once

#include "Arduino.h"
#include "Sensor.h"
#include "Servomotor.h"
#include "Disk.h"

class Controller {
private:
  Sensor* _hs;
  Sensor* _ps;
  Sensor* _tg;
  Servomotor* _servo;
  Disk* _disk;
  bool isActivated;
  int count;
protected:
  const int FALL_DURATION = 0;

public:
  Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk);

  int getReleaseTime();

  int getHoleDelay();

  void rele(int releaseTime);

  void photo();

  void hall();

  void trigg();
};
