#include <BleKeyboard.h>

#define NUM_KEYS 10

int keyPins[NUM_KEYS] = {18, 19, 21, 22, 23, 25, 26, 27, 32};
uint8_t keyValues[NUM_KEYS] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10};

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("MacroKeypad Connected");

  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
  }

  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    for (int i = 0; i < NUM_KEYS; i++) {
      if (digitalRead(keyPins[i]) == LOW) {
        bleKeyboard.write(KEY_LEFT_CTRL);
        bleKeyboard.write(KEY_LEFT_SHIFT);
        bleKeyboard.write(keyValues[i]);

        delay(50);

        while (digitalRead(keyPins[i]) == LOW) {
          delay(10);
        }
      }
    }
  }

  delay(10);
}
