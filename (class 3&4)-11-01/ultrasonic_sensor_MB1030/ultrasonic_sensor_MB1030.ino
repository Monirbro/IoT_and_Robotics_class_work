#define sensorPin A0  // Analog pin connected to AN (Analog Output) of MB1030

void setup() {
  Serial.begin(9600);  // Initialize Serial Monitor
}

void loop() {
  // Read the analog voltage from the sensor
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);


  // Convert the analog value to voltage (5V system, 10-bit ADC resolution)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert the voltage to distance in centimeters
  // The MB1030 outputs ~9.8mV per inch -> 0.385mV per cm
  float distanceCm = (voltage * 1000) / 0.385;

  // Print the distance
  // Serial.print("Distance: ");
  // Serial.print(distanceCm);
  // Serial.println(" cm");

  delay(100);  // Delay for stability
}
