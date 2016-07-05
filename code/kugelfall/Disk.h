#pragma once

#include "Sensor.h"

/**
 * Size of the ring puffer.
 */
#define PUFFER_SIZE 24

/**
 * A model for the disk of the experiment.
 */
class Disk {

private:

  /**
   * Number of black and white sectors.
   */
  const int N_SECTORS = 12;

  /**
   * Ring puffer to save the photosensor values.
   */
  long ring_puffer[PUFFER_SIZE] = { };

  /**
   * Last timestamp of a photosensor falling flank in milliseconds.
   */
  long t_photo_low = 0;
  /**
   * Last timestamp of a photosenor rising flank in milliseconds.
   */
  long t_photo_high = 0;
  /**
   * Last timestamp of a hallsensor rising flank in milliseconds.
   */
  long t_hall = 0;
  /**
   * current index of the ringer puffer.
   */
  int puffer_idx = 0;
  /**
   * old delta value of the photosensor.
   */
  long old_delta = 0;

  /**
   * Whether the disk is steady or not.
   */
  boolean steadiness = true;

public:

  /**
   * Class constructor.
   */
  Disk();

  /**
   * Calculates the time for one sector in milliseconds.
   * 
   * @return time between to sectors.
   */
  long getDelta();

  /**
   * Calculates the speed in cycles per seconds.
   */
  double getCyclesPerSecond();

  /**
   * Adds the given value to the ring puffer.
   */
  void setPuffer(long delta);

  /**
   * Adds a photosensor timestamp of a rising flank. 
   */
  void setPhotoHigh(long photo_high);

  /**
   * Adds a photosensor timestamp of a falling flank.
   */
  void setPhotoLow(long photo_low);

  /**
   * Sets the hallsensor timestamp.
   */
  void setHall(long hall);

  /**
   * Returns the last hallsensor timestamp.
   */
  long getHall();

  /**
   * Retrieves the maximum value of a list of values.
   */
  long getMax(long a[], int num_elements);

  /**
   * Retrieves the average value of a list of values.
   */
  long getAvg(long a[], int num_elements);

  /**
   * Whether the disk is steady or not.
   */
  boolean isSteady();

  /**
   * Detects steadiness of the disk.
   */
  void computeSteadiness(long new_delta);
};
