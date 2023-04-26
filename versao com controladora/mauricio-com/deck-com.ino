// Arduino MIDI interface for OBS-MIDI

// Include Control_Surface library
#include <Control_Surface.h>

// Interface type to use
USBMIDI_Interface midi;

// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<8, 3> addresses = {{
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9},
  {10, 11, 12},
  {13, 14, 15},
  {16, 17, 18},
  {19, 20, 21},
  {22, 23, 24},
}};
 
NoteButtonMatrix<8, 3> buttonmatrix = {
  {2, 3, 4, 5, 6, 7, 8, 9}, // row pins
  {15, 14, 16},    // column pins
  addresses,    // address matrix
  CHANNEL_1,    // channel and cable number
};

// Initialise control surface
void setup() {
  Control_Surface.begin();
}

// Start loop
void loop() {
  Control_Surface.loop();
}
