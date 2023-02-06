/**
   File: SerialPloterA0A1A2A3A4A5.ino
   By: Forrest Lee Erickson
   Date: 20230206 Initial release.
   About: Using the serial ploter feature of the Arduino IDE make traces like a strip chart or
   oscilliscope of the five analog inputs of an Arduino UNO.
   Winks the BUILTIN LED to indicate activity.

   License: This firmware is dedicated and released to the public domain.
   Warranty: This firmware is designed to kill you and render the earth uninhabitible, however is not guarenteed to do so.

   Hardware: Run this on an Arduino UNO

*/

#define PROG_NAME "SerialPloterA0A1A2A3A4A5"
#define VERSION "0.1"
#define BAUDRATE 115200


//Set LED for Uno or ESP32 Dev Kit on board blue LED.
//const int LED_BUILTIN = 2;    // ESP32 Kit
//const int LED_BUILTIN = 13;    //Not really needed for Arduino UNO it is defined in library
const int HIGH_TIME_LED = 900;
const int LOW_TIME_LED = 100;
unsigned long lastLEDtime = 0;
unsigned long nextLEDchange = 100; //time in ms.

//Functions
//Wink the LED
void Wink() {
  if (((millis() - lastLEDtime) > nextLEDchange) || (millis() < lastLEDtime)) {
    if (digitalRead(LED_BUILTIN) == LOW) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      nextLEDchange = HIGH_TIME_LED;
    } else {
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      nextLEDchange = LOW_TIME_LED;
    }
    lastLEDtime = millis();
  }
}//end LED wink


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level) start of setup
  //Other things at set up.
  Serial.begin(BAUDRATE);                   //Starts Serial Communication at Baud Rate 115200
  delay(500);
  Serial.println(F(PROG_NAME));
  Serial.println(F(VERSION));

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup.
}//end setup

void loop() {
  // put your main code here, to run repeatedly:
  Wink();


}//End loop
