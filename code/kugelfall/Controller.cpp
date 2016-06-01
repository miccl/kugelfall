#include "Controller.h"

Controller::Controller(Sensor* ps, Sensor* hs, Sensor* tg, Servomotor* servo, Disk* disk) : _ps(ps), _hs(hs), _servo(servo), _tg(tg), _disk(disk) {
	// erstmal nur schemenhaft gemacht. auch die funktionsbezeichnungen sind nicht ideal.
 // der compiler meckert da auch rum. auf die schnelle habe ich da keine loesung gefunden.
	//attachInterrupt(digitalPinToInterrupt(ps->getPin()), photo, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(hallSensor->getPin()), hall, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(trigger->getPin()), trigg, CHANGE);

}

int Controller::getReleaseTime() {
	// TODO - implement Controller::getReleaseTime
}

int Controller::getHoleDelay() {
	// TODO - implement Controller::getHoleDelay
}

void Controller::rele(int releaseTime) {
	// TODO - implement Controller::release
}

void Controller::photo() {
	
}

void Controller::hall() {

}

void Controller::trigg() {
  count++;
  isActivated = true;
}
