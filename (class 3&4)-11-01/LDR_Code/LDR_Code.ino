#define ldrPin A0  // Analog pin connected to the LDR
#define ledPin 8   // Digital pin connected to the LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read the value from the LDR
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);  // Print the LDR value to the Serial Monitor

  // If the light level is low (darkness), turn the LED ON
  if (ldrValue < 25) {           // Adjust the threshold based on your environment
    digitalWrite(ledPin, HIGH);  // Turn the LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Turn the LED OFF
  }

  delay(100);  // Short delay to stabilize readings
}
