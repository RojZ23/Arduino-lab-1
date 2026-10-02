/*
  B-3: Random Disco Party Lights

  Wiring:
    D8  -> 330 ohm resistor -> red LED
    D9  -> 330 ohm resistor -> yellow LED
    D10 -> 330 ohm resistor -> green LED
    D11 -> 330 ohm resistor -> blue LED
    D12 -> 330 ohm resistor -> white LED

  Every LED cathode (short leg) connects to Arduino GND.

  Important:
    Leave analog pin A0 unconnected. It is used only as a changing
    random seed when the Arduino starts.
*/

// Array containing all five LED pins.
const int discoLedPins[5] = {8, 9, 10, 11, 12};

// Number of LEDs in the array.
const int numberOfLeds = 5;


void setup() {
  // Configure all LED pins as outputs.
  for (int index = 0; index < numberOfLeds; index++) {
    pinMode(discoLedPins[index], OUTPUT);

    // Start with all LEDs off.
    digitalWrite(discoLedPins[index], LOW);
  }

  // Seed Arduino's pseudo-random generator.
  // A0 should be left unconnected for this sketch.
  randomSeed(analogRead(A0));
}


void loop() {
  // Choose an LED array position from 0 through 4.
  int selectedLed = random(0, numberOfLeds);

  // Randomly choose HIGH (on) or LOW (off).
  int selectedState = random(0, 2);

  // Apply the randomly selected state to the randomly selected LED.
  digitalWrite(discoLedPins[selectedLed], selectedState);

  // Random delay between 50 ms and 250 ms.
  // The upper limit is excluded by random(), so this yields 50-249 ms.
  delay(random(50, 250));
}