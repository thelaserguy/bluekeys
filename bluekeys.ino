#include <BleKeyboard.h>

#define NUM_KEYS 10

const int keyPins[NUM_KEYS] = {18, 19, 21, 22, 23, 25, 26, 27, 32};  // array of pins where keys are connected
const uint8_t keyValues[NUM_KEYS] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10};  // change this to match your keys

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("MacroKeypad Connected");

  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);  // configure key pins as inputs with pullup resistors
  }
  
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    for (int i = 0; i < NUM_KEYS; i++) {
      if (digitalRead(keyPins[i]) == LOW) {  // if key is pressed (LOW because of pullup resistor)
        bleKeyboard.write(KEY_LEFT_CTRL);
        bleKeyboard.write(KEY_LEFT_SHIFT);
        bleKeyboard.write(keyValues[i]);  // send key combination
        delay(200);  // basic & crude debouncing - gonna want to improve this
      }
    }
  }
  delay(10);  // short delay to avoid hogging the CPU
}
