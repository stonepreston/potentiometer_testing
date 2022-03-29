#include <Arduino.h>
#include <Control_Surface.h>
// include the ResponsiveAnalogRead library
#include <ResponsiveAnalogRead.h>

// define the pin you want to use
const int ANALOG_PIN = A17;

USBDebugMIDI_Interface midi {9600};
ResponsiveAnalogRead analog(ANALOG_PIN, true);

void setup() {
  analog.setAnalogResolution(4096);
  analog.setActivityThreshold(10.0f);
  Control_Surface.begin(); 
}

void loop() {
  // update the ResponsiveAnalogRead object every loop
  analog.update();

  Serial.print(analog.getRawValue());
  Serial.print("\t");
  Serial.print(analog.getValue());
  
  // if the repsonsive value has change, print out 'changed'
  if(analog.hasChanged()) {
    Serial.print("\tchanged");
  }
  
  Serial.println("");
  delay(20);
}
