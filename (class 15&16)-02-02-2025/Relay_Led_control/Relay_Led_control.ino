#define RELAY_PIN 8  // Relay connected to D2

void setup() {
    pinMode(RELAY_PIN, OUTPUT);  // Set relay pin as output
    Serial.begin(9600);  // Start Serial Monitor
}

void loop() {
    Serial.println("Turning LED ON");
    digitalWrite(RELAY_PIN, HIGH);  // Turn relay ON (LED ON)
    delay(2000);  // Wait for 2 seconds

    Serial.println("Turning LED OFF");
    digitalWrite(RELAY_PIN, LOW);   // Turn relay OFF (LED OFF)
    delay(2000);  // Wait for 2 seconds
}
