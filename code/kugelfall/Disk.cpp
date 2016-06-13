#include "Disk.h"

Disk::Disk() {
  
}

long Disk::getDelta() {
  long t_photo = t_low > t_high ? t_low - t_high : t_high - t_low; //get the absolute value of the difference of the times
  return t_photo;
}

