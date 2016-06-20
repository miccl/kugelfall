#include "Disk.h"

Disk::Disk() {
  
}

long Disk::getDelta() {
  long t_photo = t_photo_low > t_photo_high ? t_photo_low - t_photo_high : t_photo_high - t_photo_low; //get the absolute value of the difference of the times
  return t_photo;
}

double Disk::getCyclesPerSecond() {
  long t_cycle_ms = getDelta() * N_SECTORS;
  return t_cycle_ms/1000;
}

