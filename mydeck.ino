#include "Keyboard.h"
#include <Keypad.h>
#include <Control_Surface.h>

USBMIDI_Interface midi;

const byte ROWS = 3;
const byte COLS = 8;

char keys[COLS][ROWS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'10', '11', '12'},
  {'13', '14', '15'},
  {'16', '17', '18'},
  {'19', '20', '21'},
  {'22', '23', '24'},
};

byte rowPins[ROWS] = {15, 14, 16};
byte colPins[COLS] = {2, 3, 4, 5, 6, 7, 8, 9};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Control_Surface.begin();
    Serial.begin(9600);
  Keyboard.begin();
}

void sendMacroCommand(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
}

void loop() {
    Control_Surface.loop();
      char key = keypad.getKey();

    if (key) {
      Serial.println(key);
      switch (key) {
        case '1':
          sendMacroCommand(KEY_F1);
          break;
        case '2':
          sendMacroCommand(KEY_F2);
          break;
        case '3':
          sendMacroCommand(KEY_F3);
          break;
        case '4':
          sendMacroCommand(KEY_F4);
          break;
        case '5':
          sendMacroCommand(KEY_F5);
          break;
        case '6':
          sendMacroCommand(KEY_F6);
          break;
        case '7':
          sendMacroCommand(KEY_F7);
          break;
        case '8':
          sendMacroCommand(KEY_F8);
          break;
        case '9':
          sendMacroCommand(KEY_F9);
          break;
        case '10':
          sendMacroCommand(KEY_F10);
          break;
        case '11':
          sendMacroCommand(KEY_F11);
          break;
        case '12':
          sendMacroCommand(KEY_F12);
          break;
        case '13':
          sendMacroCommand(KEY_F13);
          break;
        case '14':
          sendMacroCommand(KEY_F14);
          break;
        case '15':
          sendMacroCommand(KEY_F15);
          break;
        case '16':
          sendMacroCommand(KEY_F16);
          break;
        case '17':
          sendMacroCommand(KEY_F17);
          break;
        case '18':
          sendMacroCommand(KEY_F18);
          break;
        case '19':
          sendMacroCommand(KEY_F19);
          break;
        case '20':
          sendMacroCommand(KEY_F20);
          break;
        case '21':
          sendMacroCommand(KEY_F21);
          break;
        case '22':
          sendMacroCommand(KEY_F22);
          break;
        case '23':
          sendMacroCommand(KEY_F23);
          break;
        case '24':
          sendMacroCommand(KEY_F24);
          break;
      }

    delay(100);
    Keyboard.releaseAll();
  }
}
