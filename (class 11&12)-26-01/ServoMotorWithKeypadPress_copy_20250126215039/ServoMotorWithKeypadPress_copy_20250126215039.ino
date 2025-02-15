#include <Keypad.h>
#include <Servo.h>

// Define keypad dimensions
const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns

// Define the key map
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Define the pin numbers for rows and columns
byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3, 2 };  // Connect to the column pinouts of the keypad

// Create an object for the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Create a servo object
Servo myServo;

// Variables for storing user input
String inputNumber = "";  // Stores the number entered by the user

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  myServo.attach(10);  // Attach the servo to pin 10
  myServo.write(0);    // Start the servo at 0 degrees
  Serial.println("Enter a number and press # to confirm.");
}

void loop() {
  char key = keypad.getKey();  // Get the key pressed from the keypad

  if (key) {
    // If '#' is pressed, execute the servo movement
    if (key == '#') {
      if (inputNumber.length() > 0) {      // Check if a number was entered
        int cycles = inputNumber.toInt();  // Convert the input to an integer
        Serial.print("Number of cycles: ");
        Serial.println(cycles);

        // Perform the servo movement for the specified number of cycles
        for (int j = 0; j < cycles; j++) {
          Serial.print("Cycle: ");
          Serial.println(j + 1);

          // Move the servo from 0 to 90 degrees
          for (int i = 0; i <= 90; i++) {
            myServo.write(i);  // Move to angle i
            delay(10);         // Small delay for smooth movement
          }

          // Move the servo back from 90 to 0 degrees
          for (int i = 90; i >= 0; i--) {
            myServo.write(i);  // Move to angle i
            delay(10);         // Small delay for smooth movement
          }
        }
        Serial.println("All cycles completed!");
      } else {
        Serial.println("No number entered. Please enter a number and press #.");
      }
      inputNumber = "";  // Clear the input after execution
    }
    // If a number is pressed, add it to the input string
    else if (key >= '0' && key <= '9') {
      inputNumber += key;
      Serial.print("Current Input: ");
      Serial.println(inputNumber);
    }
    // If an invalid key is pressed, show an error
    else {
      Serial.println("Invalid key. Please enter numbers and press #.");
    }
  }
}




// #include <Keypad.h>
// #include <Servo.h>

// // Define keypad dimensions
// const byte ROWS = 4;  // Four rows
// const byte COLS = 4;  // Four columns

// // Define the key map
// char keys[ROWS][COLS] = {
//   { '1', '2', '3', 'A' },
//   { '4', '5', '6', 'B' },
//   { '7', '8', '9', 'C' },
//   { '*', '0', '#', 'D' }
// };

// // Define the pin numbers for rows and columns
// byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Connect to the row pinouts of the keypad
// byte colPins[COLS] = { 5, 4, 3, 2 };  // Connect to the column pinouts of the keypad

// // Create an object for the keypad
// Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// // Create a servo object
// Servo myServo;

// void setup() {
//   Serial.begin(9600);  // Initialize serial communication
//   myServo.attach(10);  // Attach the servo to pin 10
//   myServo.write(0);    // Start the servo at 0 degrees
//   Serial.println("Press a key to move the servo.");
// }

// void loop() {
//   char key = keypad.getKey();  // Get the key pressed from the keypad

//   // If a key is pressed, process it
//   if (key) {
//     Serial.print("Key Pressed: ");
//     Serial.println(key);

//     // Convert the pressed key to an integer (number of cycles)
//     int cycles = key - '0';  // Convert char to int

//     // If the key is a valid number (0-9)
//     if (cycles >= 0 && cycles <= 9) {
//       Serial.print("Servo will move ");
//       Serial.print(cycles);
//       Serial.println(" times.");

//       // Perform the servo movement for the specified number of cycles
//       for (int j = 0; j < cycles; j++) {
//         Serial.print("Cycle: ");
//         Serial.println(j + 1);

//         // Move the servo from 0 to 90 degrees
//         for (int i = 0; i <= 90; i++) {
//           myServo.write(i);  // Move to angle i
//           delay(10);         // Small delay for smooth movement
//         }

//         // Move the servo back from 90 to 0 degrees
//         for (int i = 90; i >= 0; i--) {
//           myServo.write(i);  // Move to angle i
//           delay(10);         // Small delay for smooth movement
//         }
//       }
//       Serial.println("All cycles completed!");
//     } else {
//       Serial.println("Invalid key. Please press a number between 0-9.");
//     }
//   }
// }





// // #include <Keypad.h>
// // #include <Servo.h>

// // // Define keypad dimensions
// // const byte ROWS = 4;  // Four rows
// // const byte COLS = 4;  // Four columns

// // // Define the key map
// // char keys[ROWS][COLS] = {
// //   { '1', '2', '3', 'A' },
// //   { '4', '5', '6', 'B' },
// //   { '7', '8', '9', 'C' },
// //   { '*', '0', '#', 'D' }
// // };

// // // Define the pin numbers for rows and columns
// // byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Connect to the row pinouts of the keypad
// // byte colPins[COLS] = { 5, 4, 3, 2 };  // Connect to the column pinouts of the keypad

// // // Create an object for the keypad
// // Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// // // Create a servo object
// // Servo myServo;

// // int currentAngle = 0;  // Track the current angle of the servo

// // void setup() {
// //   Serial.begin(9600);           // Initialize serial communication
// //   myServo.attach(10);           // Attach the servo to pin 10
// //   myServo.write(currentAngle);  // Start at 0 degrees
// //   Serial.println("Press any key to move the servo.");
// // }

// // void loop() {
// //   char key = keypad.getKey();  // Get the key pressed from the keypad

// //   // If a key is pressed, process it
// //   if (key) {
// //     Serial.print("Key Pressed: ");
// //     Serial.println(key);

// //     // Move the servo incrementally from 0 to 90 degrees for each key press
// //     for (int i = 0; i <= 90; i++) {
// //       myServo.write(i);  // Move to angle i
// //       delay(20);         // Wait for the servo to reach the angle
// //     }

// //     // After reaching 90, go back from 90 to 0
// //     for (int i = 90; i >= 0; i--) {
// //       myServo.write(i);  // Move back to angle i
// //       delay(20);         // Wait for the servo to reach the angle
// //     }
// //   }
// // }
