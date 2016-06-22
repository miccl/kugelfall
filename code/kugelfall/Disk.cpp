#include "Disk.h"

Disk::Disk() {
}

long Disk::getDelta() {
  long max = getMax(ring_puffer, PUFFER_SIZE);
  Serial.print(max, DEC);
  Serial.print(",");
  Serial.println(getAvg(ring_puffer, PUFFER_SIZE), DEC);
  //delay(1);
  //return getMax(ring_puffer, PUFFER_SIZE);
  return max;
}

double Disk::getCyclesPerSecond() {
  long t_cycle_ms = getDelta() * N_SECTORS;
  return 1/(t_cycle_ms/1000.0);
}

void Disk::setPuffer(long value) {
  ring_puffer[puffer_idx] = value;
  puffer_idx = (puffer_idx + 1) % PUFFER_SIZE;
  //test_stopp(value)
  //test_stopp(getDelta());
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
  int i = 0;
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

void Disk::test_stopp(long new_delta) {
  long stop_diff = 50;
  long start_diff = 100;
  if (new_delta > (old_delta + stop_diff)) {
    stopped = true;
    Serial.print("STOPP:");
    Serial.print(old_delta);
    Serial.print(",");
    Serial.println(new_delta);
  } 
//  else if (new_delta <  (old_delta - start_diff)) {
//    Serial.println("START");
//    stopped = false;
//  }  else if (new_delta > 2000) {
//    stopped = false;
//  }
  old_delta = new_delta;

}

