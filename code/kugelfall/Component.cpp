#include "Component.h"

Component::Component(int pin) : _pin(pin){
  
}

int Component::getPin() {
  return _pin;
}
