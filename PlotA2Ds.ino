/*Plot the A2Ds of Arduino UNO


*/

#define MIN_VOLTAGE "-0.1"
#define MAX_VOLTAGE "5.1"


unsigned long lastADCtime = 0;
unsigned long nextADCcapture = 100; //time in ms.




//Plot the A2Ds
void PlotA2Ds() {
  //For A0 to A1 plot the ADC values and min and max axis
  if (((millis() - lastADCtime) > nextADCcapture) || (millis() < lastADCtime)) {
    lastADCtime = millis(); // Grab the time so that the next sample will be more independant of this processing time.
    //Time to capture and print
    Serial.print(F(MIN_VOLTAGE));
    Serial.print(", ");
    Serial.print(analogRead(A0));
    Serial.print(", ");  
    Serial.print(analogRead(A1));
    Serial.print(", ");  
    Serial.print(analogRead(A2));
    Serial.print(", ");  
    Serial.print(analogRead(A3));
    Serial.print(", ");  
    Serial.print(analogRead(A4));
    Serial.print(", ");  
    Serial.print(analogRead(A5));
    Serial.println(F(MAX_VOLTAGE));
    lastADCtime = millis();
  }
}//end PlotA2Ds
