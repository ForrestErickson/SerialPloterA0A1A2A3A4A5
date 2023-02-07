/**
   File: SerialPloterA0A1A2A3A4A5.ino
   By: Forrest Lee Erickson
   Date: 20230206 Initial release.
   About: Using the serial ploter feature of the Arduino IDE make traces like a strip chart or
   oscilliscope of the six analog inputs of an Arduino UNO.
   Winks the BUILTIN LED to indicate activity.

   License: This firmware is dedicated and released to the public domain.
   Warranty: This firmware is designed to kill you and render the earth uninhabitible, however is not guarenteed to do so.

   Hardware: Run this on an Arduino UNO. 

   USER INSTRUCTIONS: 
   * Edit the variable sExperimentDescription to describe the system under test and compile and upload. 
   * Plot with "Ctrl" "Shift" and "L"

*/

/* Setup the sample rate, and Edit the Plot header here for the descritpiont of the system under test. Use no spaces or delimiting puncuation.
Example  experiment descriptions:
-  sExperimentDescription "Flux_Capacitor_SN3_19850824_@1.21GW" or "CurrentStarDrive@LudicrisSpeed"
-  sExperimentDescription "SystemUnderTest_bla_bla_bla" // Change "_bla_bla_bla" for description of the experimental setup and perhaps date.
*/
const unsigned long SAMPLE_PERIOD = 50;  //Time in ms.  There are 500 points so total time is 500*SAMPLE_PERIOD
const String sExperimentDescription = "Flux_Capacitor_SN3_@1.21GW";  //Description the system under test.
//Edit the channel name if desired. For example change A0 to VoltageFluxCapacitor and A2 to CurrentFluxCapacitor and A3 to Speedometer...
const String NAME_TERACE_ZERO   = "A0";
const String NAME_TERACE_ONE    = "A1";
const String NAME_TERACE_TWO    = "A2";
const String NAME_TERACE_THREE  = "A3";
const String NAME_TERACE_FOUR   = "A4";
const String NAME_TERACE_FIVE   = "A5";
/* end of user setup */

#define PROG_NAME "SerialPloterA0A1A2A3A4A5"
#define VERSION "0.2"
#define BAUDRATE 115200

const String sHeader = "" + String(PROG_NAME) + "_Ver" + String(VERSION);     //Start of descriptive header for plot
const String sPlotName = "@" + String(SAMPLE_PERIOD) + "mS/SMPL-***" + sExperimentDescription + "***-" ;  // for end of header



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
