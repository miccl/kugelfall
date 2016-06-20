#include "Disk.h"

Disk::Disk() {
  
}

long Disk::getDelta() {
  long photo_delta;
  //Serial.println("DELTA");
  if(t_photo_low > t_photo_high) {
      photo_delta = t_photo_low - t_photo_high;
  } else {
      photo_delta = t_photo_high - t_photo_low;
  }
  if (photo_delta<25) {
    delay(1);
    return getDelta();
  }
  return photo_delta;
}

double Disk::getCyclesPerSecond() {
  long t_cycle_ms = getDelta() * N_SECTORS;
  return 1/(t_cycle_ms/1000.0);
}

