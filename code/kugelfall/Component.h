#pragma once

#include "Arduino.h"

class Component {

protected:
  int _pin;

public:
  Component(int pin);
 
  int getPin();
};
