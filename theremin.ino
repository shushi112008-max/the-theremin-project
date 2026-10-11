// Pin definitions
const int lightSensorPin = A0; // Light sensor analog A0
const int buzzerPin = 8;       // Buzzer digital 8

// Variables to store light levels
int sensorValue = 0;
int sensorMin = 1023;          //automatic calibration
int sensorMax = 0;             //automatic calibration

void setup() {
  // The first 5 seconds are for calibration DO NOT REMOVE THEM
  // Move your hand up and down over the sensor right when it turns on (SLOWLY)
  while (millis() < 5000) {
    sensorValue = analogRead(lightSensorPin);

    // Record the maximum and minimum light levels seen
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    } 
  }
}

void loop() {
  // Read the current light level
  sensorValue = analogRead(lightSensorPin);

  // Map the light reading to a musical frequency (pitch)
  // Higher light = higher pitch, shadow = lower pitch
  int pitch = map(sensorValue, sensorMin, sensorMax, 50, 1000);

  // Play the sound for 10 milliseconds
  tone(buzzerPin, pitch, 10);

  // A tiny pause to let the sound play smoothly which is callibrated form of the sensor's analogue reading
  delay(10);
}
