// Soil Moisture Sensor Reading - Serial Monitor Output

// Define the sensor pin
const int sensorPin = A0;  // Analog pin connected to the sensor

void setup() {
  Serial.begin(9600);  // Start serial communication
  Serial.println("Soil Moisture Sensor Initialized...");
}

void loop() {
  // Read the analog value from the sensor
  int sensorValue = analogRead(sensorPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("Soil Moisture Level: ");
  Serial.println(sensorValue);

  // Determine soil moisture condition
  if (sensorValue >= 0 && sensorValue <= 400) {
    Serial.println("Status: Dry Soil - Water Needed!");
  } else if (sensorValue >= 401 && sensorValue <= 700) {
    Serial.println("Status: Moist Soil - Sufficient Water");
  } else {
    Serial.println("Status: Wet Soil - No Water Needed");
  }

  Serial.println("----------------------------");  // Separator for readability

  // Delay for better readability in the Serial Monitor
  delay(1000);  // Wait for 1 second
}
