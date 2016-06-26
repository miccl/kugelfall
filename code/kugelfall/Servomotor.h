#pragma once

#include <Servo.h>
#include "Actor.h"

/**
 * A servormotor hardware which is accessible by Arduino.
 */
class Servomotor : public Actor {

private:
  /**
   * The end position.
   */
	const int END_POS = 20;

  /**
   * The start position.
   */
	const int START_POS = 0;

protected:
  /**
   * Pointer to the servomotor instance.
   */
	Servo _servo;

public:

  /**
   * Class constructor.
   */
	Servomotor(int pin);

	/**
	* Opens the release.
	*/
	void open();

	/**
	* Closes the release.
	*/
	void close();
};
