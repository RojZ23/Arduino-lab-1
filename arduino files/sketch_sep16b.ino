/*
  B-1: Arduino Stoplight

  Wiring:
    D8  -> 330 ohm resistor -> red LED anode
    D9  -> 330 ohm resistor -> yellow LED anode
    D10 -> 330 ohm resistor -> green LED anode
    D12 -> 330 ohm resistor -> white LED anode (optional walk signal)

  Every LED cathode (short leg) connects to Arduino GND.

  Sequence:
    Green: 5 seconds
    Yellow: 2 seconds
    Red: 5 seconds
    Repeat
*/

// Assign each LED a descriptive pin name.
const int redLedPin = 8;
const int yellowLedPin = 9;
const int greenLedPin = 10;
const int walkLedPin = 12;  // Optional white "walk" LED.

// Timing values in milliseconds.
const int mediumTime = 5000;  // 5 seconds.
const int shortTime = 2000;   // 2 seconds.


void setup() {
  // Configure every LED pin as an output.
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(walkLedPin, OUTPUT);

  // Start with every LED off.
  allLightsOff();
}


void loop() {
  // GREEN LIGHT:
  // Cars may go. The optional walk LED is also on.
  allLightsOff();
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(walkLedPin, HIGH);
  delay(mediumTime);

  // YELLOW LIGHT:
  // Warn that the signal is about to change.
  allLightsOff();
  digitalWrite(yellowLedPin, HIGH);
  delay(shortTime);

  // RED LIGHT:
  // Cars must stop. The walk LED remains off in this simple example.
  allLightsOff();
  digitalWrite(redLedPin, HIGH);
  delay(mediumTime);
}


/*
  Turns off all LEDs.

  Using this helper prevents accidental overlap, such as having
  red and green on at the same time.
*/
void allLightsOff() {
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(walkLedPin, LOW);
}