#include <SoftwareSerial.h>


// SoftwareSerial pins
SoftwareSerial mySerial(2, 3); // RX = Pin 2, TX = Pin 3


// LED pin
const int ledPin = 8;


// Authorized number
String authorizedNumber = "+8801787305158"; // Replace with your number


void setup() {
  Serial.begin(115200);       // Serial Monitor baud rate
  mySerial.begin(115200);     // GSM module baud rate


  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.println("Initializing GSM Module...");
  delay(2000);


  // Test GSM module
  mySerial.println("AT");
  delay(1000);
  mySerial.println("AT+CLIP=1"); // Enable caller ID
  delay(1000);
  Serial.println("GSM Module Ready!");
}


void loop() {
  if (mySerial.available()) {
    String response = mySerial.readString(); // Read GSM module response
    Serial.println("Raw Response: " + response); // Debugging: Print raw response


    // Check for incoming call
    if (response.indexOf("+CLIP:") >= 0) {
      int startIdx = response.indexOf("\"") + 1; // Find start of the number
      int endIdx = response.indexOf("\"", startIdx);
      String incomingNumber = response.substring(startIdx, endIdx);


      Serial.println("Incoming call from: " + incomingNumber); // Debugging


      // Normalize incoming number by adding '+' if missing
      if (incomingNumber.charAt(0) != '+') {
        incomingNumber = "+" + incomingNumber; // Add '+' to the beginning
      }


      Serial.println("Normalized number: " + incomingNumber); // Debugging


      // Check if the number matches
      if (incomingNumber == authorizedNumber) {
        Serial.println("Authorized number detected. Turning ON LED...");
        digitalWrite(ledPin, HIGH);  // Turn on LED
        delay(10000);                // Keep LED on for 5 seconds
        digitalWrite(ledPin, LOW);  // Turn off LED
      } else {
        Serial.println("Unauthorized call.");
      }
    }
  }
}
