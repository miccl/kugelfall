#pragma once

#include "Arduino.h"
#include "Sensor.h"
#include "Servomotor.h"
#include "Disk.h"

/**
 * Controller class. 
 */
class Controller {
private:

  /**
   * Pointer to the servomotor instance.
   */
  Servomotor* _servo;
  /**
   * Pointer to the disk instance.
   */
  Disk* _disk;
  /**
   * 
   */
  int releaseEps = 100;
  
  
protected:
  /**
   * Distance between release and hole in cm.
   */
  const double S_FALL = 0.75;
  /**
   * Falling time of a ball from release to the hole.
   */
  const long T_FALL = 520;
 

public:
  /**
   * Class constructor.
   * 
   * @param servo The pointer to the servomotor instance.
   * @param disk The pointer to the disk instance.
   */
  Controller(Servomotor* servo, Disk* disk);

 /*
 * Calculates the release time.
 * 
 * @return calculated release time
 */
  long getReleaseTime();

 /**
  * Calculates a dynamic delay for given delta.
  * 
  */
 long getDynamicDelay(long delta);
 /**
 * Release a ball immediatly.
 */
  void release();

  /**
 * Waits for release.
 * During the waiting time, the release time gets updated.
 */
  void waitForRelease();

};
