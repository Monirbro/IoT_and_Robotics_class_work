const int PIR_SENSOR = 2;  // PIR sensor connected to pin 2
const int LED = 8;         // LED connected to pin 9

void setup() {
    pinMode(PIR_SENSOR, INPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int motionDetected = digitalRead(PIR_SENSOR);

    if (motionDetected == HIGH) { // If motion detected
        Serial.println("⚠ Motion Detected! LED ON.");
        digitalWrite(LED, HIGH);
    } else { 
        Serial.println("✅ No Motion. LED OFF.");
        digitalWrite(LED, LOW);
    }

    delay(500); // Small delay to avoid rapid flickering
}
