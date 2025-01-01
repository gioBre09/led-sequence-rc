RC Receiver Controlled Lights
This project uses an Arduino to control a set of position lights, strobe lights, and beacon lights based on the signal received from an RC receiver. The receiver signal is used to trigger a sequence of light patterns when the signal is active.

Features
Signal Reading: The Arduino reads a PWM signal from an RC receiver.
Light Control: Based on the signal strength, the Arduino controls three different sets of lights (Position Lights, Strobe Lights, and Beacon Lights).
Light Sequences: When the signal exceeds a threshold, the lights will follow a predefined pattern of blinking and staying on.
Components
Arduino (any model with at least 3 digital pins)
RC receiver (connected to a PWM-capable pin)
3 lights (Position Lights, Strobe Lights, Beacon Lights)
Jumper wires for connections
Pinout
RC Receiver Pin: Pin 2 (for receiving PWM signal from the RC receiver)
Position Lights Pin: Pin 13 (digital output for position lights)
Strobe Lights Pin: Pin 12 (digital output for strobe lights)
Beacon Lights Pin: Pin 11 (digital output for beacon lights)
Circuit Diagram
Ensure you connect the RC receiver signal to pin 2 and the lights to pins 11, 12, and 13. The ground and power connections should be properly handled according to your setup.

Code Explanation
Setup
The RC_PIN is set to pin 2, which receives the PWM signal from the RC receiver.
The light pins are set to output mode.
The SIGNAL_THRESHOLD is defined as 1500, which means the signal must exceed this value to be considered "active."
Loop
The Arduino reads the signal from the RC receiver using pulseIn().
If the signal exceeds the threshold, it triggers a light sequence:
Three blinks in 2 seconds (all lights turn on for 200 ms, then off for 467 ms).
Lights stay on for 1 second.
Lights stay off for 0.7 seconds.
If the signal is not active, all the lights are turned off.
Signal Debugging
The received signal value is printed to the serial monitor for debugging purposes.
Installation
Requirements
Arduino IDE (for uploading the code to the Arduino)
Arduino board (e.g., Uno, Mega)
RC receiver for PWM signal
3 lights (LEDs or similar) connected to pins 11, 12, and 13
Steps to Set Up
Connect the RC receiver to pin 2 of your Arduino.
Connect your lights to pins 11, 12, and 13. Ensure each light is connected with an appropriate current-limiting resistor.
Open the Arduino IDE and paste the code from the RC Controlled Lights project.
Select your board and port in the Tools menu.
Upload the code to your Arduino board.
Open the Serial Monitor (optional) to view the signal values.
Usage
When the signal from the RC receiver is above the threshold (1500), the Arduino will trigger a sequence of lights as described above.
If the signal falls below the threshold, the lights will remain off.
Customization
You can adjust the SIGNAL_THRESHOLD to fine-tune when the lights will activate based on your RC signal.
The timing of the light sequences can also be modified by adjusting the delay values.
License
This project is open source and available under the MIT License.

