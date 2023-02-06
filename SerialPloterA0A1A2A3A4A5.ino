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


//Functions


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level) start of setup
  //Other things at set up.
  Serial.begin(BAUDRATE);                   //Starts Serial Communication at Baud Rate 115200
  delay(500);

//Print program and version is incompatible with setting the plot legend  
//  Serial.println(F(PROG_NAME));
//  Serial.println(F(VERSION));

  PrintPlotLegend();

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off at end of setup.
}//end setup

void loop() {
  // put your main code here, to run repeatedly:
  Wink();
  PlotA2Ds();


}//End loop
