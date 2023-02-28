#include <Arduino.h>
#include <Control_Surface.h>

// Instantiate a MIDI Interface to use
USBMIDI_Interface midi;

// Instantiate a MIDI Debug interface at 115200 baud.
//USBDebugMIDI_Interface midi = 115200;

// Instantiate four Banks, with two tracks per bank. 
Bank<2> bank(2);
//   │       └───── number of tracks per bank
//   └───────────── number of banks

// A/D-IN 1-5 / D-IN6
CCButton input1 {18, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_1}};
CCButton input2 {19, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_2}};
CCButton input3 {20, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_3}};
CCButton input4 {21, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_4}};
CCButton input5 { 4, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_5}};
CCButton input6 { 5, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_6}};  // DIN only

CCButton switch1 { 7, {MIDI_CC::General_Purpose_Controller_2, CHANNEL_1}};
CCButton switch2 {15, {MIDI_CC::General_Purpose_Controller_2, CHANNEL_2}};
CCButton switch3 {16, {MIDI_CC::General_Purpose_Controller_2, CHANNEL_3}};
CCButton switch4 {14, {MIDI_CC::General_Purpose_Controller_2, CHANNEL_4}};

Bankable::CCPotentiometer potentiometer1 {
  {bank, BankType::CHANGE_CHANNEL},
  A7,
  {MIDI_CC::Channel_Volume, CHANNEL_1},
};

Bankable::CCPotentiometer potentiometer2 {
  {bank, BankType::CHANGE_CHANNEL},
  A8,
  {MIDI_CC::Channel_Volume, CHANNEL_2},
};

Bankable::CCPotentiometer potentiometer3 {
  {bank, BankType::CHANGE_CHANNEL},
  A9,
  {MIDI_CC::Channel_Volume, CHANNEL_3},
};

Bankable::CCPotentiometer potentiometer4 {
  {bank, BankType::CHANGE_CHANNEL},
  A10,
  {MIDI_CC::Channel_Volume, CHANNEL_4},
};

// NoteLED led1 { 0, MIDI_Notes::C(1) };
// NoteLED led2 { 1, MIDI_Notes::C(2) };
// NoteLED led3 { 2, MIDI_Notes::C(3) };
// NoteLED led4 { 3, MIDI_Notes::C(4) };

// Initialize the Control Surface
void setup() {
  Control_Surface.begin();
}
 
// Update the Control Surface
void loop() {
  Control_Surface.loop();
}