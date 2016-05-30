/**
 * sensor value capturing
 * gets the sensor values and write them into a file.
 */

// sensors
const int photoPin = 2;
const int hallPin = 3;
const int button1Pin = 10;
bool pressed = false;

void setup() {
  pinMode(photoPin, INPUT);
  pinMode(hallPin, INPUT);
  pinMode(button1Pin, INPUT);
  
  Serial.begin(9600);           // set up Serial library at 9600 bps

}

void loop() {
  if(digitalRead(button1Pin)) {
    pressed = true;
  }
  
  if(!pressed) {
    long time = millis();
    bool hallState = digitalRead(hallPin);
    bool photoState = digitalRead(photoPin);
    Serial.print(time);
    Serial.print(",");
    Serial.print(hallState, DEC);
    Serial.print(",");
    Serial.print(photoState, DEC);
    Serial.println();
  }  
  delay(10);
}
