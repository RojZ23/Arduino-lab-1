/*
  C-4: Random ASCII Art to Serial Monitor

  This program:
    - Stores two ASCII-art cat pictures in String variables.
    - Randomly selects one picture.
    - Prints one picture per second.
    - Prints three pictures, pauses, then repeats.

  Important escape characters:
    \n  means print a new line.
    \\  means print one backslash character.
*/

// First ASCII cat picture from the assignment example.
// Each \\ in the code prints one \ in the Serial Monitor.
String catPicOne =
  "  ^~^  '\n"
  " ('Y') )\n"
  " /   \\/ \n"
  "(\\|||/)";

// Second cat picture.
String catPicTwo =
  " /\\_/\\\\\n"
  "( o.o )\n"
  " > ^ <";


void setup() {
  // Start communication with the Serial Monitor.
  Serial.begin(9600);

  // Give the Serial Monitor a moment to open after upload.
  delay(500);

  // Print a heading once.
  Serial.println("-------------------");
  Serial.println("C-4 Random ASCII Cats");
  Serial.println("-------------------");

  /*
    Start the pseudo-random generator at a different location.
    A0 should be left unconnected for this program.
  */
  randomSeed(analogRead(A0));
}


void loop() {
  // Print an ASCII art picture three times.
  for (int pictureCount = 1; pictureCount <= 3; pictureCount++) {
    // random(0, 2) returns either 0 or 1.
    int chosenPicture = random(0, 2);

    // Print which picture was selected.
    Serial.print("Picture ");
    Serial.print(pictureCount);
    Serial.println(":");

    // Print one of the two cats.
    if (chosenPicture == 0) {
      Serial.println(catPicOne);
    } else {
      Serial.println(catPicTwo);
    }

    // Print a blank line after each picture.
    Serial.println();

    // Wait one second before the next random picture.
    delay(1000);
  }

  // Print an end marker after the set of three pictures.
  Serial.println("----- Three pictures printed -----");
  Serial.println();

  // Pause before restarting the three-picture sequence.
  delay(2000);
}