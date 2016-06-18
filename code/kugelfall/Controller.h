#pragma once

#include "Arduino.h"
#include "Sensor.h"
#include "Servomotor.h"
#include "Disk.h"

class Controller {
private:
  Servomotor* _servo;
  Disk* _disk;
  bool isActivated;
  int count;
  int releaseEps = 100;
  
  
protected:
  const double S_FALL = 0.75;
  const double FALL_ACCLERATION = 9.81;
  const long T_FALL = 450;

public:
  Controller(Servomotor* servo, Disk* disk);

 /*
 * Calculates the release time for the given hole time.
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
