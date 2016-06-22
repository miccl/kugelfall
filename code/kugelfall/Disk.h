#pragma once

#include "Sensor.h"

#define PUFFER_SIZE 20

class Disk {

private:
  const int N_SECTORS = 12;
  const double S_ARC = S_DISK/N_SECTORS;
  const double S_HOLE = 0.06;
  const double S_DISK = 1;
  
  long ring_puffer[PUFFER_SIZE] = { };

  long t_photo_low = 0;
  long t_photo_high = 0;
  long t_hall = 0;
  int puffer_idx = 0;
  long old_delta = 0;
  
public:
  boolean stopped = true;

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

  
  void setPuffer(long delta);

  void setPhotoHigh(long photo_high);

  void setPhotoLow(long photo_low);

  void setHall(long hall);

  long getHall();

  long getMax(long a[], int num_elements);

  long getAvg(long a[], int num_elements);

  void test_stopp(long new_delta);
};
