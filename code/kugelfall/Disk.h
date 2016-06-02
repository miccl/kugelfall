#pragma once

#include "Sensor.h"

class Disk {

private:
  const int ARC_LENGTH = 1;
  bool isWaiting;
  int getDiff(int t1, int t2);
  
  Sensor* _ps;

public:
  int t_low;
  int t_high;

  Disk(Sensor* ps);

  int getSpeed();
};
