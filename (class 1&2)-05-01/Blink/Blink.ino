// the setup function runs once when you press reset or power the board
const int led=7;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW); 
  digitalWrite(led, LOW);  // turn the LED off by making the voltage LOW
  delay(100);    
  //digitalRead()                  // wait for a second
}
