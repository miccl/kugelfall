#include "Disk.h"

Disk::Disk(Sensor* ps) : _ps(ps) {
  
}

int Disk::getSpeed() {
  int t = t_low > t_high ? t_low - t_high : t_high - t_low;
  int speed = ARC_LENGTH / t;
  return speed;
}

