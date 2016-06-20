#pragma once

#include "Arduino.h"

#define DEBUG 0

class Component {

protected:
  int _pin;

public:
  Component(int pin);
 
  int getPin();
};
