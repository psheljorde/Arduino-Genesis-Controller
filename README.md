# Arduino-Genesis-Controller
This is a fork of burks10 Arduino-SNES-Controller meant to work with a SEGA Genesis 3 button controller.


## Hardware Setup

Genesis Controller Pinout
<pre>
</pre>
 <ul>
 </ul>
 
## Software Setup
<ol>
  <li>Install the Drivers by running to UnoJoy/UnoJoyDriverInstaller.bat</li>
  <li>Open the code located under genesis/genesis.ino and upload it to your Arduino.</li>
  <li>The Arduino UNO R2/R3 uses a MEGA16u2 chip to upload sketches to memory. In order to be recognized as an HID USB device,
  we must flash the 16u2 chip with some custom firmware. To do this on the Arduino R3, short the 2 pins closest to the USB port to enter
  DFU mode. From there, run UnoJoy/TurnIntoAJoystick.bat. Now that you have reflashed the Arduino, unplug it from the USB and re-plug it
  back in. You are now running the arduino as a joystick.</li>
  
</ol>

Be sure to checkout UnoJoy (https://github.com/AlanChatham/UnoJoy) for their awesome library/drivers that made this project possible.
Thanks to burks10 for the original code, you should check him out (http://github.com/burks10/Arduino-SNES-Controller).
