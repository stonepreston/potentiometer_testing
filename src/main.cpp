#include <Arduino.h>
#include <Control_Surface.h>
// include the ResponsiveAnalogRead library
#include <ResponsiveAnalogRead.h>

// define the pin you want to use
const int ANALOG_PIN = A17;

USBDebugMIDI_Interface midi {9600};

// make a ResponsiveAnalogRead object, pass in the pin, and either true or false depending on if you want sleep enabled
// enabling sleep will cause values to take less time to stop changing and potentially stop changing more abruptly,
//   where as disabling sleep will cause values to ease into their correct position smoothly and more accurately
ResponsiveAnalogRead analog(ANALOG_PIN, true);

// the next optional argument is snapMultiplier, which is set to 0.01 by default
// you can pass it a value from 0 to 1 that controls the amount of easing
// increase this to lessen the amount of easing (such as 0.1) and make the responsive values more responsive
// but doing so may cause more noise to seep through if sleep is not enabled

void setup() {
//   Control_Surface.begin(); // THIS CAUSES WERID BEHAVIOR!!! IF I COMMENT THIS OUT THINGS WORK AS EXPECTED
//  IF I DONT COMMENT IT OUT, THE ANALOG READ IS NOISY/ONLY READS HALF THE POT VALUES
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
