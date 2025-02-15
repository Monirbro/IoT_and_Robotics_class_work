#include <SoftwareSerial.h>

// Define GSM module RX and TX pins
SoftwareSerial mySerial(2, 3);  // GSM TX → Arduino Pin 2, GSM RX → Arduino Pin 3

// Define LED pin
const int ledPin = 8;

void setup() {
  Serial.begin(115200);  // Debugging
  mySerial.begin(9600);  // ✅ Most GSM modules use 9600 baud rate

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Ensure LED is initially OFF

  Serial.println("Initializing GSM Module...");
  delay(2000);

  // Configure GSM module
  sendCommand("AT");                 // Check GSM module
  sendCommand("AT+CMGF=1");          // Set SMS mode to text
  sendCommand("AT+CNMI=2,2,0,0,0");  // Auto-display incoming SMS
  sendCommand("AT+CLIP=1");          // Enable caller ID

  Serial.println("✅ GSM Module Ready!");
}

void loop() {
  if (mySerial.available()) {
    String response = mySerial.readString();  // Read response from GSM
    Serial.println("Raw Response: " + response);

    // Check for SMS
    if (response.indexOf("+CMT:") >= 0) {
      handleIncomingSMS(response);
    }
  }
}

// Function to handle incoming SMS
void handleIncomingSMS(String response) {
  Serial.println("📩 Processing SMS...");

  // Extract phone number
  int startIdx = response.indexOf("+CMT: \"") + 7;
  int endIdx = response.indexOf("\"", startIdx);
  if (startIdx < 7 || endIdx == -1) {
    Serial.println("⚠ Error parsing number!");
    return;
  }

  String senderNumber = response.substring(startIdx, endIdx);
  senderNumber.trim();
  if (senderNumber.charAt(0) != '+') {
    senderNumber = "+" + senderNumber;
  }

  Serial.println("📞 Sender: " + senderNumber);

  // Extract SMS message
  int msgStart = response.indexOf("\n", endIdx) + 1;
  if (msgStart > 1) {
    String message = response.substring(msgStart);
    message.replace("\r", "");  // Remove carriage returns
    message.replace("\n", "");  // Remove newlines
    message.trim();             // Remove extra spaces

    Serial.println("📜 Message received: '" + message + "'");

    // LED Control via SMS
    if (message.equalsIgnoreCase("ON")) {
      digitalWrite(ledPin, HIGH);
      Serial.println("✅ LED Turned ON");
      sendSMS(senderNumber, "LED is ON");
    } else if (message.equalsIgnoreCase("OFF")) {
      digitalWrite(ledPin, LOW);
      Serial.println("✅ LED Turned OFF");
      sendSMS(senderNumber, "LED is OFF");
    } else {
      Serial.println("⚠ Invalid command received.");
      sendSMS(senderNumber, "Invalid Command! Send 'ON' or 'OFF'");
    }
  } else {
    Serial.println("⚠ Error extracting message body!");
  }
}

// Function to send SMS
void sendSMS(String number, String text) {
  Serial.println("📤 Sending SMS to: " + number);
  mySerial.println("AT+CMGS=\"" + number + "\"");
  delay(1000);

  mySerial.print(text);
  delay(500);

  mySerial.write(26);  // CTRL+Z to send SMS
  delay(3000);

  Serial.println("✅ SMS Sent: " + text);
}

// Function to send AT commands
void sendCommand(String cmd) {
  mySerial.println(cmd);
  delay(1000);
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
