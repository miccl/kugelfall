#include "Controller.h"

Controller::Controller(Sensor* ps, Sensor* hs, Servomotor* sm, Trigger* tg) : photoSensor(ps), hallSensor(hs), servomotor(sm), trigger(tg) {
	// erstmal nur schemenhaft gemacht. auch die funktionsbezeichnungen sind nicht ideal.
 // der compiler meckert da auch rum. auf die schnelle habe ich da keine loesung gefunden.
	//attachInterrupt(digitalPinToInterrupt(photoSensor->getPin()), photo, CHANGE);
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

}
