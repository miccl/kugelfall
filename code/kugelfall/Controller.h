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
  const double S_FALL = 0.75;
  const double FALL_ACCLERATION = 9.81;
  const double T_FALL = sqrt(2*(S_FALL/FALL_ACCLERATION));

public:
  Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk);

  int getReleaseTime(long t_loch);

  int getHoleDelay();

  void release();
  
  void release(int releaseTime);
};
