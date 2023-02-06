/*Plot the A2Ds of Arduino UNO


*/

#define MIN_VOLTAGE "0"
#define MAX_VOLTAGE "5"

//This is the Sample period 
const unsigned long SAMPLE_PERIOD = 100;  //Time in ms.

unsigned long lastADCtime = 0;
unsigned long nextADCcapture = SAMPLE_PERIOD; //time in ms.


void PrintPlotLegend() {
  //Send first to set plot legend.
  Serial.print("Min");
  Serial.print(", ");
  Serial.print("A0");
  Serial.print(", ");
  Serial.print("A1");
  Serial.print(", ");
  Serial.print("A2");
  Serial.print(", ");
  Serial.print("A3");
  Serial.print(", ");
  Serial.print("A4");
  Serial.print(", ");
  Serial.print("A5");
  Serial.print(", ");
  Serial.println("Max");
}

//Plot the A2Ds
void PlotA2Ds() {
  //For A0 to A1 plot the ADC values and min and max axis
  if (((millis() - lastADCtime) > nextADCcapture) || (millis() < lastADCtime)) {
    lastADCtime = millis(); // Grab the time so that the next sample will be more independant of this processing time.
    //Time to capture and print
    Serial.print(F(MIN_VOLTAGE));
    Serial.print(", ");
    Serial.print(analogRead(A0)*5.0/1023);
    Serial.print(", ");
    Serial.print(analogRead(A1)*5.0/1023);
    Serial.print(", ");
    Serial.print(analogRead(A2)*5.0/1023);
    Serial.print(", ");
    Serial.print(analogRead(A3)*5.0/1023);
    Serial.print(", ");
    Serial.print(analogRead(A4)*5.0/1023);
    Serial.print(", ");
    Serial.print(analogRead(A5)*5.0/1023);
    Serial.print(", ");
    Serial.println(F(MAX_VOLTAGE));
//    lastADCtime = millis();
  }
}//end PlotA2Ds
