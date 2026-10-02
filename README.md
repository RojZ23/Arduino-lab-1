# Arduino-lab
# Lab 03: Arduino Outputs and LEDs

In this lab, I used an **Arduino Uno**, a breadboard, jumper wires, LEDs, resistors, and the Arduino IDE with the Serial Monitor. The purpose of the lab was to practice controlling Arduino output pins and using code to make LEDs blink, fade, display patterns, and respond to commands from a computer.

## Materials Used

- Arduino Uno board  
- Breadboard  
- LEDs in different colors  
- Current-limiting resistors, such as 220 Ω  
- Jumper wires  
- USB cable and computer  
- Arduino IDE and Serial Monitor  

## What I Did

I connected external LEDs to the Arduino’s digital GPIO pins, including pin 13 and other digital pins. I programmed the LEDs to turn on and off in different patterns, including an S.O.S. Morse code signal.

I also used Pulse Width Modulation (PWM) to control LED brightness. I created a fading effect by gradually changing the amount of time the LED was on and off, then used the Arduino’s built-in PWM output functions to make the LED dim and brighten more easily.

For the multiple-LED section, I programmed LEDs to behave like a traffic light by cycling through green, yellow, and red. I also used several LEDs to count in binary from 0 to 15 and back down. Another activity used LEDs as random “disco” lights.

Finally, I used the Serial Monitor to print messages and a running number count from the Arduino. I modified the output format, printed ASCII art, and tested sending text from the Serial Monitor to the Arduino so that typed commands could be used to control an LED.
