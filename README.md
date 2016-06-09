# Arduino-Genesis-Controller
This is a fork of burks10 Arduino-SNES-Controller meant to work with a SEGA Genesis 3 button controller.


## Hardware Setup

Genesis Controller Pinout

<pre>
    ___________
    \1 2 3 4 5/
     \6 7 8 9/

</pre>

| DB9 pin         | Arduino pin   |
|:-------------   | -------------:|
| 1 - Up          |            11 |
| 2 - Down        |             2 |
| 3 - Left        |             3 |
| 4 - Right       |             4 |
| 5 - 5V          |            5V |
| 6 - A/B         |             6 |
| 7 - Select      |             7 |
| 8 - GND         |           GND |
| 9 - START/C     |             9 |

Order: Low/High

## Software Setup

  1. Install the Drivers by running to UnoJoy/UnoJoyDriverInstaller.bat
  2. Open the code located under genesis/genesis.ino and upload it to your Arduino.
  3.The Arduino UNO R2/R3 uses a MEGA16u2 chip to upload sketches to memory. In order to be recognized as an HID USB device,
  we must flash the 16u2 chip with some custom firmware. To do this on the Arduino R3, short the 2 pins closest to the USB port to enter
  DFU mode. From there, run UnoJoy/TurnIntoAJoystick.bat. Now that you have reflashed the Arduino, unplug it from the USB and re-plug it
  back in. You are now running the arduino as a joystick.
  

Be sure to checkout [UnoJoy](https://github.com/AlanChatham/UnoJoy) for their awesome library/drivers that made this project possible.

Thanks to burks10 for the original code, [you should check him out](http://github.com/burks10/Arduino-SNES-Controller).
