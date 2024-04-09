///// IMPORTANT
// install this on Arduino IDE: https://github.com/MHeironimus/ArduinoJoystickLibrary
//
// Download https://github.com/MHeironimus/ArduinoJoystickLibrary/archive/master.zip
// In the Arduino IDE, select Sketch > Include Library > Add .ZIP Library ...
// ... Browse to where the downloaded ZIP file is located and click Open.
/////

#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  pinMode(A3, INPUT); // A3 - default analog pin
  Joystick.begin();
}


void loop() {
  Joystick.setThrottle(analogRead(ANALOG_PIN));
}
