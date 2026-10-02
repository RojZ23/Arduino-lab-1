/*
  C-5: Control an Arduino LED from the Serial Monitor

  This program reads text sent from the Arduino IDE Serial Monitor.

  Commands to type:
    ON      Turn the built-in LED on.
    OFF     Turn the built-in LED off.
    TOGGLE  Switch the LED between on and off.
    STATUS  Print the current LED state.
    HELP    Print the list of available commands.

  Serial Monitor configuration:
    - Baud rate: 9600
    - Line ending: Newline, or Both NL & CR
*/

const int ledPin = LED_BUILTIN;

// Holds the current LED state.
bool ledIsOn = false;

// Stores characters received from the Serial Monitor until a line ends.
String incomingCommand = "";


void setup() {
  // Configure the built-in LED as an output.
  pinMode(ledPin, OUTPUT);

  // Start with the LED turned off.
  digitalWrite(ledPin, LOW);

  // Start serial communication.
  Serial.begin(9600);

  // Print instructions for the user.
  Serial.println("------------------------------");
  Serial.println("C-5 Serial LED Controller");
  Serial.println("Type ON, OFF, TOGGLE, STATUS, or HELP.");
  Serial.println("Set Serial Monitor line ending to Newline.");
  Serial.println("------------------------------");
}


void loop() {
  /*
    Serial.available() is greater than 0 when one or more incoming
    characters are waiting to be read.
  */
  while (Serial.available() > 0) {
    // Read one character at a time from the Serial Monitor.
    char receivedCharacter = Serial.read();

    /*
      A newline '\n' or carriage return '\r' means the user pressed
      Send, so the whole command has arrived.
    */
    if (receivedCharacter == '\n' || receivedCharacter == '\r') {
      // Remove surrounding spaces and stray line-ending characters.
      incomingCommand.trim();

      // Only process the command when something was actually typed.
      if (incomingCommand.length() > 0) {
        processCommand(incomingCommand);

        // Clear the string so it is ready for the next command.
        incomingCommand = "";
      }
    } else {
      // Add normal typed characters to the command String.
      incomingCommand += receivedCharacter;
    }
  }
}


/*
  Examines a complete text command and performs the appropriate action.
*/
void processCommand(String command) {
  // Convert text to uppercase so "on", "On", and "ON" all work.
  command.toUpperCase();

  // Echo the received command back to the terminal.
  Serial.print("Received command: ");
  Serial.println(command);

  if (command == "ON") {
    // Turn LED on.
    ledIsOn = true;
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is now ON.");
  }
  else if (command == "OFF") {
    // Turn LED off.
    ledIsOn = false;
    digitalWrite(ledPin, LOW);
    Serial.println("LED is now OFF.");
  }
  else if (command == "TOGGLE") {
    // Reverse the saved LED state.
    ledIsOn = !ledIsOn;
    digitalWrite(ledPin, ledIsOn ? HIGH : LOW);

    if (ledIsOn) {
      Serial.println("LED toggled ON.");
    } else {
      Serial.println("LED toggled OFF.");
    }
  }
  else if (command == "STATUS") {
    // Report the current state without changing the LED.
    if (ledIsOn) {
      Serial.println("Current LED status: ON.");
    } else {
      Serial.println("Current LED status: OFF.");
    }
  }
  else if (command == "HELP") {
    // Show all valid commands.
    Serial.println("Available commands: ON, OFF, TOGGLE, STATUS, HELP");
  }
  else {
    // Handle invalid commands.
    Serial.println("Unknown command. Type HELP for valid commands.");
  }

  // Print a blank line to make separate commands easier to read.
  Serial.println();
}