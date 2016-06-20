#include "Disk.h"

Disk::Disk() {
}

long Disk::getDelta() {
  return getMax(ring_puffer, PUFFER_SIZE);
}

double Disk::getCyclesPerSecond() {
  long t_cycle_ms = getDelta() * N_SECTORS;
  return 1/(t_cycle_ms/1000.0);
}

void Disk::setPuffer(long value) {
  ring_puffer[puffer_idx] = value;
  puffer_idx = (puffer_idx + 1) % PUFFER_SIZE;
}

void Disk::setPhotoHigh(long value) {
  t_photo_high = value;
  setPuffer(t_photo_high - t_photo_low);
}

void Disk::setPhotoLow(long value) {
  t_photo_low = value;
  setPuffer(t_photo_low - t_photo_high);
}

void Disk::setHall(long value) {
  t_hall = value;
}

long Disk::getHall() {
  return t_hall;
}

long Disk::getMax(long a[], int num_elements) {
  int i, max=0;
  for (i=0; i<num_elements; i++) {
   if (a[i]>max) {
      max=a[i];
   }
 }
 return max;
}

