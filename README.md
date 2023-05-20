# Bluetooth Mechanical Keyboard

This repository contains code and design files for a Bluetooth mechanical keyboard using an ESP32 and Cherry MX keys.

## Project Description

This project is designed to create a custom mechanical keyboard that uses Bluetooth to communicate with other devices. The keys are Cherry MX switches, each wired to an ESP32, which acts as a Bluetooth keyboard. When a key is pressed, it sends a specific key combination (CTRL+SHIFT+F*) over Bluetooth, which can be used to trigger actions on any connected device.

## Getting Started

### Prerequisites

- ESP32
- 9 Cherry MX keys
- Laser cut or 3D printed case (the one in this project is laser cut)
- Arduino IDE with BleKeyboard library installed

### Wiring

One post of the keys is wired to ground, and the other posts are wired to the following pins: 18, 19, 21, 22, 23, 25, 26, 27, 32.

### Installation

1. Clone this repository
2. Open the Arduino IDE
3. Install the BleKeyboard library (if not already installed)
4. Open the .ino file from this repository
5. Choose the correct board and port in the Arduino IDE
6. Click Upload

## Usage

Once you've uploaded the code to your ESP32, you can pair your new "keyboard" with your computer (or any other Bluetooth device) and start testing it out!

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/)

## Contact

- Website: [thelaserguy.co](https://thelaserguy.co)
- Links: [links.thelaserguy.co](https://links.thelaserguy.co)
