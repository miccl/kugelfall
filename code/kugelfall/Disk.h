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
  int t_low;
  int t_high;
  const double S_DISK = 1;


  Disk(Sensor* ps);

  /**
   * Calculates the speed of the disk
   * 
   * @return the current disk speed
   */
  double getSpeed();
};
