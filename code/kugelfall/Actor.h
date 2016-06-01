#pragma once

#include "Component.h"

class Actor : public Component {

public:
	Actor(int pin);

	void setValue(int value);
};
