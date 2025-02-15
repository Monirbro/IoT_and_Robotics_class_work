// Define pins
const int sensorPin = A0;  // Analog pin connected to the sensor
const int ledPin1 = 6;
const int ledPin2 = 9;
const int ledPin3 = 12;  // Digital pin connected to the LED
int sensorValue = 0;     // Variable to store sensor reading

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);        // Start serial communication
}

void loop() {
  // Read the analog value from the sensor
  sensorValue = analogRead(sensorPin);

  // // Print the sensor value to the Serial Monitor
  // Serial.print("Soil Moisture Level: ");
  // Serial.println(sensorValue);

  // Determine soil moisture level
  Serial.println(sensorValue);

  if (sensorValue >= 0 && sensorValue <= 400) 
  {  // Adjust threshold as needed
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);  // Red LED OFF
    digitalWrite(ledPin3, LOW);  // Turn on LED (dry soil)
    //Serial.println(sensorValue);
  } 
  else if (sensorValue >= 401 && sensorValue <= 700) 
  {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);  // Red LED OFF
    digitalWrite(ledPin3, LOW);  // Turn off LED (wet soil)
    //Serial.println(sensorValue);
  } else 
  {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, LOW);  // Red LED OFF
    digitalWrite(ledPin1, LOW);  //Turn off LED (wet soil)
    //Serial.println(sensorValue);
  }

  delay(1000);  // Wait for 1 second
}
