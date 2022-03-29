#include <Arduino.h>
#include <Control_Surface.h>
#include <ResponsiveAnalogRead.h>

const int ANALOG_PIN = A4;
ResponsiveAnalogRead analog(ANALOG_PIN, true);

// Instantiate a MIDI over USB interface.
USBMIDI_Interface midi;

// PBPotentiometer pitchBendPotentiometer = {
//         A4,        // Analog pin connected to potentiometer
//         CHANNEL_1, // MIDI Channel 1
// };
PitchBendSender<10> pbSender;

void setup() {

    Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
    Control_Surface.loop(); // Update the Control Surface
    analog.update();
    if(analog.hasChanged()) {
        pbSender.send(analog.getValue(), CHANNEL_1);
    }
    
    delay(20);
}