#include <BleKeyboard.h>

#define NUM_KEYS 10

// Define arrays for key pins and key values
int keyPins[NUM_KEYS];
uint8_t keyValues[NUM_KEYS];

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("MacroKeypad Connected");

  // Configure key pins as inputs with pullup resistors
  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
  }

  bleKeyboard.begin();
}

void loop() {
  // Check if the BLE keyboard is connected
  if (bleKeyboard.isConnected()) {
    for (int i = 0; i < NUM_KEYS; i++) {
      // Check if the key is pressed (LOW due to pullup resistor)
      if (digitalRead(keyPins[i]) == LOW) {
        // Send the key combination
        bleKeyboard.write(KEY_LEFT_CTRL);
        bleKeyboard.write(KEY_LEFT_SHIFT);
        bleKeyboard.write(keyValues[i]);

        // Wait for a short delay for debouncing
        delay(50);

        // Wait until the key is released
        while (digitalRead(keyPins[i]) == LOW) {
          delay(10);
        }
      }
    }
  }

  // Add a short delay to avoid hogging the CPU
  delay(10);
}
