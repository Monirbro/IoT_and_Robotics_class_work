// /*
// This is a simple demo of sending and receiving some data.
//   Be sure to check out other examples!
//  *******/

// /* Fill-in information from Blynk Device Info here */
// // #define BLYNK_TEMPLATE_ID "TMPL6sOtpL78v"
// // #define BLYNK_TEMPLATE_NAME "Quickstart Template"
// // #define BLYNK_AUTH_TOKEN "a2R0wCPqT69MdiNqTx34WyiEXud0j90c"
// /*************************************************************

//   This is a simple demo of sending and receiving some data.
//   Be sure to check out other examples!
//  *************************************************************/

// /* Fill-in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID           "TMPL61KCnjsXC"
// #define BLYNK_TEMPLATE_NAME         "Quickstart Template"
// #define BLYNK_AUTH_TOKEN            "SYcGxu72Vft6koysPkxlIBaDvNGGAHcw"

// /* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial


// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>

// // Your WiFi credentials.
// // Set password to "" for open networks.
// char ssid[] = "Birmingham";
// char pass[] = "*12345*12345*";

// BlynkTimer timer;

// // This function is called every time the Virtual Pin 0 state changes
// BLYNK_WRITE(V0)
// {
//   // Set incoming value from pin V0 to a variable
//   int value = param.asInt();

//   // Update state
//   Blynk.virtualWrite(V1, value);
// }

// // This function is called every time the device is connected to the Blynk.Cloud
// BLYNK_CONNECTED()
// {
//   // Change Web Link Button message to "Congratulations!"
//   Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
//   Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
//   Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
// }

// // This function sends Arduino's uptime every second to Virtual Pin 2.
// void myTimerEvent()
// {
//   // You can send any value at any time.
//   // Please don't send more that 10 values per second.
//   Blynk.virtualWrite(V2, millis() / 1000);
// }

// void setup()
// {
//   // Debug console
//   Serial.begin(115200);

//   Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
//   // You can also specify server:
//   //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
//   //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

//   // Setup a function to be called every second
//   timer.setInterval(1000L, myTimerEvent);
// }

// void loop()
// {
//   Blynk.run();
//   timer.run();
//   // You can inject your own code or combine it with other sketches.
//   // Check other examples on how to communicate with Blynk. Remember
//   // to avoid delay() function!
// }


#define BLYNK_TEMPLATE_ID "TMPL61KCnjsXC"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "gNyx7D5fnmTzuZ5-ZxnuRfEqNDmRn1U1"
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
float c, h, f, k;
#include "SparkFun_SHTC3.h"  // Click here to get the library: http://librarymanager/All#SparkFun_SHTC3

SHTC3 mySHTC3;  // Declare an instance of the SHTC3 class

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Birmingham";
char pass[] = "*12345*12345*";

int pot = 0;

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0) {
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
  value = !value;
  digitalWrite(LED_BUILTIN, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED() {
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent() {
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup() {
  // Debug console
  Serial.begin(115200);
  while (Serial == false) {};                          // Wait for the serial connection to start up
  Serial.println("SHTC3 Example 1 - Basic Readings");  // Title
  Wire.begin(4, 5);
  Serial.print("Beginning sensor. Result = ");  // Most SHTC3 functions return a variable of the type "SHTC3_Status_TypeDef" to indicate the status of their execution
  errorDecoder(mySHTC3.begin());                // To start the sensor you must call "begin()", the default settings use Wire (default Arduino I2C port)
  Serial.println();
  Serial.println("\n\n");
  Serial.println("Waiting for 5 seconds so you can read this info ^^^");

  delay(5000);
  pinMode(LED_BUILTIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(2000L, myTimerEvent);
}

void loop() {
  Blynk.run();
  timer.run();
  SHTC3_Status_TypeDef result = mySHTC3.update();  // Call "update()" to command a measurement, wait for measurement to complete, and update the RH and T members of the object
  printInfo();                                     // This function is used to print a nice little line of info to the serial port
  delay(1000);
  pot = analogRead(A0);
  Serial.println(pot);
  if (pot < 800) Blynk.virtualWrite(V1, 1);
  else Blynk.virtualWrite(V1, 0);
  //delay(100);
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

void printInfo() {
  if (mySHTC3.lastStatus == SHTC3_Status_Nominal)  // You can also assess the status of the last command by checking the ".lastStatus" member of the object
  {
    Serial.println("RH = ");
    Serial.println(mySHTC3.toPercent());  // "toPercent" returns the percent humidity as a floating point number
    Serial.println("%, T = ");
    float val = mySHTC3.toDegF();
    Serial.println(val);
    Serial.println(" deg F");
    float c = ((val - 32) / 9) * 5;
    Serial.println(c);  // "toDegF" and "toDegC" return the temperature as a flaoting point number in deg F and deg C respectively
    Serial.println(" deg c");
    Serial.print("RH = ");
    h = mySHTC3.toPercent();
    Serial.print(mySHTC3.toPercent());  // "toPercent" returns the percent humidity as a floating point number

    Blynk.virtualWrite(V5, h);

    f = mySHTC3.toDegF();
    Serial.print("%, T = ");
    Serial.print(mySHTC3.toDegF());  // "toDegF" and "toDegC" return the temperature as a flaoting point number in deg F and deg C respectively
    Serial.print(" deg F,  ");
    Blynk.virtualWrite(V0, f);
    c = mySHTC3.toDegC();
    Serial.print(mySHTC3.toDegC());  // "toDegF" and "toDegC" return the temperature as a flaoting point number in deg F and deg C respectively
    Serial.print(" deg C,  ");
    Blynk.virtualWrite(V4, c);
    Serial.print(mySHTC3.toDegC() + 273.15);  // "toDegF" and "toDegC" return the temperature as a flaoting point number in deg F and deg C respectively
    Serial.println(" K");




  } else {
    Serial.print("Update failed, error: ");
    errorDecoder(mySHTC3.lastStatus);
    Serial.println();
  }
}

void errorDecoder(SHTC3_Status_TypeDef message)  // The errorDecoder function prints "SHTC3_Status_TypeDef" resultsin a human-friendly way
{
  switch (message) {
    case SHTC3_Status_Nominal: Serial.print("Nominal"); break;
    case SHTC3_Status_Error: Serial.print("Error"); break;
    case SHTC3_Status_CRC_Fail: Serial.print("CRC Fail"); break;
    default: Serial.print("Unknown return code"); break;
  }
}