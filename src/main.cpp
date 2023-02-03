#include <Arduino.h>
#include <Control_Surface.h>

// Instantiate a MIDI Interface to use
USBMIDI_Interface midi;

// Instantiate four Banks, with two tracks per bank. 
Bank<2> bank(2);
//   │       └───── number of tracks per bank
//   └───────────── number of banks
 
NoteButton button1 {
  0, // GPIO0 has a push button connected on most boards
  MIDI_Notes::C(4), 
};

NoteButton button2 {
  1,
  MIDI_Notes::D(4), 
};

// Instantiate two potentiometers for the volume controls.
Bankable::CCPotentiometer potentiometer1 {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A0,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_1}, // address
};
Bankable::CCPotentiometer potentiometer2 {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A1,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_2}, // address
};

// Initialize the Control Surface
void setup() {
  Control_Surface.begin();
}
 
// Update the Control Surface
void loop() {
  Control_Surface.loop();
}