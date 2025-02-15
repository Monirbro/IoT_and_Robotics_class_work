#include <Keypad.h>

// Define the number of rows and columns in the keypad
const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns

// Define the keypad layout
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Define the pin connections for rows and columns
byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3, 2 };  // Connect to the column pinouts of the keypad

// Create an object of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String currentInput = "";       // To store the entered sequence
const String PASSWORD = "211";  // Set the correct password (example: 211)

void setup() {
  Serial.begin(9600);
  Serial.println("Enter password:");
}

void loop() {
  char key = keypad.getKey();  // Read the key pressed

  if (key) {
    // Display the key pressed in the Serial Monitor
    Serial.print(key);

    if (key == '#') {
      // Check if the password is correct when '#' is pressed
      if (currentInput == PASSWORD) {
        Serial.println("\nOK");  // Password matched
      } else {
        Serial.println("\nWrong");  // Password mismatch
      }
      currentInput = "";  // Reset the input for the next round
    } else {
      // Append the key to the current input sequence
      currentInput += key;

      // Limit the input length to 3 characters only
      if (currentInput.length() > 3) {
        currentInput = "";  // Reset if too many characters are entered
        // Serial.println("\nInput cleared (too many characters). Enter 3 digits followed by #.");
      }
    }
  }
}
