#include "Disk.h"

Disk::Disk(Sensor* ps) : _ps(ps) {
  
}

double Disk::getSpeed() {
  int t_delta = t_low > t_high ? t_low - t_high : t_high - t_low; //get the absolute value of the difference of the times
  double speed = S_ARC / t_delta;
  return speed;
}

