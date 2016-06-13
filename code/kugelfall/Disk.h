#pragma once

#include "Sensor.h"

class Disk {

private:
  const int N_SECTORS = 12;
  const double S_ARC = S_DISK/N_SECTORS;
  const double S_HOLE = 0.06;
  bool isWaiting;  

public:
  long t_low = 0;
  long t_high = 0;
  long t_hall = 0;
  const double S_DISK = 1;


  Disk();

  /**
   * Calculates the time for one sector in ms.
   * 
   * @return 
   */
  long getDelta();

  /**
   * Calculates the speed in cycles per seconds.
   */
  double getCyclesPerSecond();
};
