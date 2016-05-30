/**
 * sensor value capturing
 * gets the sensor values and write them into a file.
 */

#include "Sensor.h"

// sensors
const int photoPin = 2;
const int hallPin = 3;

HallSensor* hs;
PhotoSensor* ps;
Servomotor* servo;
Disk* disk;

PrintWriter output;

void setup() {
  hs = new Sensor(hallPin);
  ps = new Sensor(photoPin);
  Serial.begin(9600);           // set up Serial library at 9600 bps

}

void loop() {
  hallState = hs.getValue();
  output.print(hallState, DEC);
  output.print(",");
  photoState = ps.getValue();
  output.print(photoState, DEC);
  output.println();
  Serial.print("SENSORWERTERFASSUNG");
}
