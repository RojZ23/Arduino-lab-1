/*
  B-2: Four-LED Binary Counter

  Wiring:
    D8  -> 330 ohm resistor -> red LED    (bit 3 / value 8)
    D9  -> 330 ohm resistor -> yellow LED (bit 2 / value 4)
    D10 -> 330 ohm resistor -> green LED  (bit 1 / value 2)
    D11 -> 330 ohm resistor -> white LED   (bit 0 / value 1)

  Every LED cathode (short leg) connects to Arduino GND.

  The LEDs count:
    0 (0000) upward to 15 (1111),
    then downward to 0 (0000),
    and repeat.
*/

// Store the pins in order from least-significant bit to most-significant bit.
// Index 0 represents bit 0 (value 1).
// Index 3 represents bit 3 (value 8).
const int binaryLedPins[4] = {11, 10, 9, 8};

// Time to display each binary number, in milliseconds.
const int countDelay = 750;


void setup() {
  // Configure all four LED pins as outputs.
  for (int index = 0; index < 4; index++) {
    pinMode(binaryLedPins[index], OUTPUT);
  }

  // Begin with 0 displayed: 0000.
  displayBinaryNumber(0);
}


void loop() {
  // Count upward from 0 (0000) to 15 (1111).
  for (int number = 0; number <= 15; number++) {
    displayBinaryNumber(number);
    delay(countDelay);
  }

  // Count back down from 14 to 0.
  // Start at 14 so that 15 is not displayed twice in a row.
  for (int number = 14; number >= 0; number--) {
    displayBinaryNumber(number);
    delay(countDelay);
  }
}


/*
  Displays a number from 0 to 15 in binary using four LEDs.

  The expression:
      number & (1 << bitPosition)

  checks whether a particular binary bit is 1.

  Examples:
    number = 5 -> binary 0101
    bit 0 = 1 -> white LED on
    bit 1 = 0 -> green LED off
    bit 2 = 1 -> yellow LED on
    bit 3 = 0 -> red LED off
*/
void displayBinaryNumber(int number) {
  // Check each of the four bit positions: 0, 1, 2, and 3.
  for (int bitPosition = 0; bitPosition < 4; bitPosition++) {
    // If the selected bit equals 1, turn its LED on.
    if (number & (1 << bitPosition)) {
      digitalWrite(binaryLedPins[bitPosition], HIGH);
    } else {
      // Otherwise, turn its LED off.
      digitalWrite(binaryLedPins[bitPosition], LOW);
    }
  }
}