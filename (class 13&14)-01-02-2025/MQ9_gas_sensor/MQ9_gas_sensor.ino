const int MQ9_A0 = A0;  // Analog pin for MQ-9 sensor
const int MQ9_D0 = 11;  // Digital pin for MQ-9
const int LED = 7;      // LED connected to pin 9

void setup() {
  Serial.begin(9600);
  pinMode(MQ9_D0, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int gasValue = analogRead(MQ9_A0);      // Read analog gas level
  int gasDetected = digitalRead(MQ9_D0);  // Read digital gas status

  Serial.print("Gas Level: ");
  Serial.println(gasValue);
  Serial.println(gasDetected);
  if (gasDetected = 0) {  // If gas is detected
    Serial.println(" NO Gas Detected! Turning LED OFF.");
    digitalWrite(LED, LOW);
  } else {
    Serial.println("✅ Gas Detected. LED ON.");
    digitalWrite(LED, HIGH);
  }

  delay(1000);  // Wait 1 second
}
