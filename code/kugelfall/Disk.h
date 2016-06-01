#pragma once

#include "Sensor.h"

class Disk {

private:
  const int ARC_LENGTH = 1;
  bool isWaiting;

public:
  Disk(Sensor* ps);

  int getSpeed();
};
