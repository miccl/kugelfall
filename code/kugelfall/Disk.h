#pragma once

#include "Sensor.h"

class Disk {

private:
  const int NUMBER_SECTORS = 12;
  const double S_ARC = S_DISK/NUMBER_SECTORS;
  const double S_HOLE = 0.06;
  bool isWaiting;  
  Sensor* _ps;

public:
  long t_low = 0;
  long t_high = 0;
  long t_hall = 0;
  const double S_DISK = 1;


  Disk(Sensor* ps);

  /**
   * Calculates the speed of the disk
   * 
   * @return the current disk speed
   */
  long getDelta();

};
