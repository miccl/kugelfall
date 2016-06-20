#pragma once

#include "Sensor.h"

class Disk {

private:
  const int N_SECTORS = 12;
  const double S_ARC = S_DISK/N_SECTORS;
  const double S_HOLE = 0.06;
  const double S_DISK = 1;

  
public:
  long t_photo_low = 0;
  long t_photo_high = 0;
  long t_hall = 0;


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
