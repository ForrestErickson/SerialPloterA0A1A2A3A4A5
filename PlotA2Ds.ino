/*Plot the A2Ds of Arduino UNO
 * Sends data in formate for the Arduino IDE serial plot function.

*/

#define MIN_VOLTAGE "0"
#define MAX_VOLTAGE "5.0"

const float fMAX_VOLTAGE = 5.0;

unsigned long lastADCtime = 0;
unsigned long nextADCcapture = SAMPLE_PERIOD; //time in ms.  This is the Sample period.

/* Send once to create a descriplive legend at top of plot */
void PrintPlotLegend() {
  //Send first to set plot legend.
  Serial.print(sHeader);
  Serial.print(", ");
 // Serial.print("A0");
  Serial.print(NAME_TERACE_ZERO);
  Serial.print(", ");
  Serial.print(NAME_TERACE_ONE);
  Serial.print(", ");
  Serial.print(NAME_TERACE_TWO);
  Serial.print(", ");
  Serial.print(NAME_TERACE_THREE);
  Serial.print(", ");
  Serial.print(NAME_TERACE_FOUR);
  Serial.print(", ");
  Serial.print(NAME_TERACE_FIVE);
  Serial.print(", ");

  // Finish the legend with descriptive plot name plus compile date and time
  String sDateAndTime = "";
  sDateAndTime = sDateAndTime + String(__DATE__) + "-"  ;
  sDateAndTime.replace(" ", "-");                           //remove ploting delimieters
  sDateAndTime = sDateAndTime + String(__TIME__)  ;
  sDateAndTime = sDateAndTime + "-"  ;
  sDateAndTime.replace(":", "-");                          //remove ploting delimieters

  String endLegend = "";
  endLegend = endLegend + "_SETUP" + sPlotName + "TIME_";  //Print the setup
  endLegend = endLegend + sDateAndTime;
  Serial.println(endLegend);  //Print the setup
}

/* Send over and over again for each sample */
//Plot the A2Ds
void PlotA2Ds() {
  //For A0 to A1 plot the ADC values and min and max axis
  if (((millis() - lastADCtime) > nextADCcapture) || (millis() < lastADCtime)) {
    lastADCtime = millis(); // Grab the time so that the next sample will be more independant of this processing time.
    //Time to capture and print
    Serial.print(F(MIN_VOLTAGE));
    Serial.print(", ");
    Serial.print(analogRead(A0) * fMAX_VOLTAGE / 1023);
    Serial.print(", ");
    Serial.print(analogRead(A1) * fMAX_VOLTAGE  / 1023);
    Serial.print(", ");
    Serial.print(analogRead(A2) * fMAX_VOLTAGE  / 1023);
    Serial.print(", ");
    Serial.print(analogRead(A3) * fMAX_VOLTAGE  / 1023);
    Serial.print(", ");
    Serial.print(analogRead(A4) * fMAX_VOLTAGE  / 1023);
    Serial.print(", ");
    Serial.print(analogRead(A5) * fMAX_VOLTAGE  / 1023);
    Serial.print(", ");
    Serial.println(0);                            //Plots on x=0. This coorisponds to the end of the text which is the end of the legend.    
  }
}//end PlotA2Ds
