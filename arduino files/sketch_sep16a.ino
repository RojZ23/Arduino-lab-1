/*
  A-4: Manual PWM LED Dimmer
  --------------------------
  Arduino Uno wiring:
    Digital pin 9 -> 220 to 330 ohm resistor -> LED anode (long leg)
    LED cathode (short leg) -> GND

  This program creates PWM manually:
    - The LED turns on for part of a short cycle.
    - The LED turns off for the rest of the cycle.
    - Increasing the ON portion increases perceived brightness.

  The program fades:
    0% -> 100% brightness in about 2 seconds
    100% -> 0% brightness in about 2 seconds
    Repeat
*/

const int ledPin = 9;

// One PWM cycle lasts 1,000 microseconds = 1 millisecond.
// That produces a PWM frequency near 1,000 Hz, fast enough
// that the LED should look steadily dim or bright.
const int pwmPeriodMicroseconds = 1000;

// Amount of time between each brightness level change.
// 8 ms x 256 brightness levels is about 2 seconds.
const int fadeStepDelay = 8;


void setup() {
  // The LED must be controlled as a digital output.
  pinMode(ledPin, OUTPUT);

  // Start with LED off.
  digitalWrite(ledPin, LOW);
}


void loop() {
  // Fade from completely off (0) to fully on (255).
  for (int brightness = 0; brightness <= 255; brightness++) {
    runManualPWM(brightness, fadeStepDelay);
  }

  // Fade from fully on (255) to completely off (0).
  for (int brightness = 255; brightness >= 0; brightness--) {
    runManualPWM(brightness, fadeStepDelay);
  }
}


/*
  Produces manual PWM at one brightness level for a requested duration.

  brightness:
    0   = LED always off
    255 = LED always on
    1-254 = LED is on for a percentage of every PWM cycle

  durationMilliseconds:
    How long to maintain this brightness before the fade moves to
    the next brightness value.
*/
void runManualPWM(int brightness, int durationMilliseconds) {
  // Convert 0-255 brightness into ON time within one PWM cycle.
  int onTime = map(
    brightness,
    0,
    255,
    0,
    pwmPeriodMicroseconds
  );

  // OFF time is whatever remains in the PWM cycle.
  int offTime = pwmPeriodMicroseconds - onTime;

  // Convert the requested duration into microseconds.
  unsigned long totalTime =
    (unsigned long)durationMilliseconds * 1000;

  // Record the time at which this brightness level begins.
  unsigned long startTime = micros();

  // Keep producing PWM cycles until this brightness level has lasted
  // for the requested number of milliseconds.
  while (micros() - startTime < totalTime) {
    // Turn LED on only if brightness is above zero.
    if (onTime > 0) {
      digitalWrite(ledPin, HIGH);
      delayMicroseconds(onTime);
    }

    // Turn LED off for the rest of the PWM cycle.
    if (offTime > 0) {
      digitalWrite(ledPin, LOW);
      delayMicroseconds(offTime);
    }
  }
}