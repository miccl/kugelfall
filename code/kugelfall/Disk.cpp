#include "Disk.h"

Disk::Disk() {
}

long Disk::getDelta() {
  long max = getMax(ring_puffer, PUFFER_SIZE);
  //#ifdef DEBUG
  //Serial.print(max, DEC);
  //Serial.print(",");
  //Serial.println(getAvg(ring_puffer, PUFFER_SIZE), DEC);
  //#endif
  return max;
}

double Disk::getCyclesPerSecond() {
  long t_cycle_ms = getDelta() * N_SECTORS;
  return 1/(t_cycle_ms/1000.0);
}

void Disk::setPuffer(long delta) {
  ring_puffer[puffer_idx] = delta;
  puffer_idx = (puffer_idx + 1) % PUFFER_SIZE;
  computeSteadiness(delta);
}

void Disk::setPhotoHigh(long photo_high) {
  t_photo_high = photo_high;
  setPuffer(t_photo_high - t_photo_low);
}

void Disk::setPhotoLow(long photo_low) {
  t_photo_low = photo_low;
  setPuffer(t_photo_low - t_photo_high);
}

void Disk::setHall(long hall) {
  t_hall = hall;
}

long Disk::getHall() {
  return t_hall;
}

long Disk::getMax(long a[], int num_elements) {
  int i = 0;
  //long maxs[]
  long max = 0;
  for (i=0; i<num_elements; i++) {
   if (a[i]>max) {
      max=a[i];
   }
 }
 return max;
}

long Disk::getAvg(long a[], int num_elements) {
  int i = 0;
  long sum = 0;
  for (i=0; i<num_elements; i++) {
    sum += a[i];
  }
  return sum/num_elements;
}

boolean Disk::isSteady() {
  return steadiness;
}

void Disk::computeSteadiness(long new_delta) {
  long stop_diff = old_delta/5;
  long start_diff = 20;
  
  if ((new_delta - old_delta) > stop_diff ) {
    steadiness = false;
  } else if ((old_delta - new_delta) >  start_diff) {
    steadiness = false;
  } else {
    steadiness = true;
  }

  old_delta = new_delta;
}

