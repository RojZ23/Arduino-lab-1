/*
  C-3: Serial Monitor Count in Lines of 20

  This program:
    - Blinks the Arduino Uno built-in LED every 500 ms.
    - Prints the count to the Serial Monitor.
    - Prints 20 numbers per line.
    - Places a dash between every number.

  Example output:
    0 - 1 - 2 - 3 - 4 - ... - 19
    20 - 21 - 22 - 23 - ... - 39
*/

const int numbersPerLine = 20;

int count = 0;
int ledState = LOW;


void setup() {
  // Begin communication with the Serial Monitor at 9600 baud.
  Serial.begin(9600);

  // Print a title once when the Arduino starts.
  Serial.println("-------------------");
  Serial.println("C-3 Serial Counter");
  Serial.println("-------------------");

  // Configure the Uno's built-in LED as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  // Toggle the built-in LED state every time loop() runs.
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }

  // Apply the new LED state.
  digitalWrite(LED_BUILTIN, ledState);

  // Print the current number without moving to the next line yet.
  Serial.print(count);

  // Increase the counter after printing it.
  count++;

  /*
    If 20 values have been printed, end the line.
    count % 20 means "the remainder after count is divided by 20."
    This condition is true after 20, 40, 60, etc. values.
  */
  if (count % numbersPerLine == 0) {
    Serial.println();
  } else {
    // Print the separator between values on the same line.
    Serial.print(" - ");
  }

  // Wait half a second before printing the next number.
  delay(500);
}