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
  const long T_FALL = 450;

public:
  Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk);

 /*
 * Calculates the relase time for the given hole time.
 * 
 * @param t_hole time the hole passed the hall sensor
 * @return calculated release time
 */
  long getReleaseTime();

 /**
 * Release a ball immediatly.
 */
  void release();

  /**
 * Releases a ball at the given time.
 * 
 * @param releaseTime the time at which to release the ball.
 */
  void release(long releaseTime);
};
