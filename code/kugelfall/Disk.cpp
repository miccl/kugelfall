#include "Disk.h"

Disk::Disk(Sensor* ps) : _ps(ps) {
  
}

int Disk::getDelta() {
  int t_photo = t_low > t_high ? t_low - t_high : t_high - t_low; //get the absolute value of the difference of the times
  return t_photo;
}

