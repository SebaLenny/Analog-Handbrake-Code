///// IMPORTANT
// install this on Arduino IDE: https://github.com/MHeironimus/ArduinoJoystickLibrary
//
// Download https://github.com/MHeironimus/ArduinoJoystickLibrary/archive/master.zip
// In the Arduino IDE, select Sketch > Include Library > Add .ZIP Library ...
// ... Browse to where the downloaded ZIP file is located and click Open.
/////


#include <Joystick.h>

// CONSTS TO SETUP MANUALLY
const int LOW_LIMIT = 0;
const int LOW_DEADZONE = 16;
const int HI_LIMIT = 255;
const int HI_DEADZONE = 0;

// ANALOG PIN TO CHOOSE (A3 by default)
const int ANALOG_PIN = A3;

// DONT TOUCH
int low_limit_result = 0;
int high_limit_result = 0;
Joystick_ Joystick;

void setup() {
  pinMode(ANALOG_PIN, INPUT);
  Joystick.begin();
  low_limit_result = LOW_LIMIT + LOW_DEADZONE;
  high_limit_result = HI_LIMIT - HI_DEADZONE;
}


void loop() {
  int analogValue = analogRead(ANALOG_PIN);
  int mappedValue = map(analogValue, low_limit_result, high_limit_result, 0, 255);
  {
    Joystick.setThrottle(mappedValue);
  }
}
