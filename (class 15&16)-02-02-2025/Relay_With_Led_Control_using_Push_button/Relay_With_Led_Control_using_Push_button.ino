#define RELAY_PIN 8   // Relay connected to D3
#define BUTTON_PIN 7  // Push button connected to D2

bool relayState = false;  // Variable to track relay state

void setup() {
  pinMode(RELAY_PIN, OUTPUT);         // Set relay pin as OUTPUT
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Enable pull-up resistor for button
  Serial.begin(9600);                 // Start Serial Monitor
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {                // If button is pressed
    delay(200);                                        // Debounce delay to avoid multiple presses
    relayState = !relayState;                          // Toggle relay state
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);  // Turn relay ON/OFF

    Serial.println(relayState ? "Relay ON" : "Relay OFF");

    while (digitalRead(BUTTON_PIN) == LOW)
      ;  // Wait until button is released
  }
}
