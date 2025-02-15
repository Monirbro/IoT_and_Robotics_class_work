#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int lm35_pin = A0;             // Pin connected to the LM35 temperature sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize LCD at I2C address 0x27, 16x2 size

String scrollingMessage = "Sumaia, Ummatun, Nishat Tasnim Mon, Tawhid, Mredul, Ismail Hossain! ";
int scrollIndex = 0;  // Starting index for scrolling

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.clear();         // Clear LCD display
  lcd.backlight();     // Turn on the backlight
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  // Read the temperature value from the LM35 sensor
  int temp_adc_val = analogRead(lm35_pin);
  Serial.println(temp_adc_val);
  float temp_val = (temp_adc_val * 4.88) / 10;  // Convert ADC value to temperature in °C

  // Display temperature on the LCD
  lcd.setCursor(0, 0);  // Set cursor to the first row
  lcd.print("Temp = ");
  lcd.print(temp_val);  // Print temperature value
  lcd.print(" C   ");   // Ensure spaces to clear remaining characters
  //Serial.println(temp_val);  // Output temperature to Serial Monitor
  // Scroll the message on the second row
  lcd.setCursor(0, 1);            // Set cursor to the second row
  for (int i = 0; i < 16; i++) {  // Display a slice of the scrolling message
    int charIndex = (scrollIndex + i) % scrollingMessage.length();
    lcd.print(scrollingMessage[charIndex]);
  }
  scrollIndex++;  // Increment the scrolling index
  if (scrollIndex >= scrollingMessage.length()) {
    scrollIndex = 0;  // Reset index to loop the message
  }
  delay(500);  // Small delay for smooth scrolling
}
