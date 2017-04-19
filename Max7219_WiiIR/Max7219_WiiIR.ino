#include "LedControl.h"
#include <IRVision.h>
#include <Wire.h>
// Definitions pins and number of modules in the circuit 
LedControl mydisplay=LedControl(12,11,10,1);
unsigned int Y,one,ten,hundred,thousand=0;
unsigned int X,one1,ten1,hundred1,thousand1=0;
IRVision IRC;
byte result;
void setup() 
{
  mydisplay.shutdown(0, false);  // turns on display
  mydisplay.setIntensity(0, 15); // 15 = brightest
  Serial.begin(115200);
  IRC.init();
  
}

void loop() 
{
 mydisplay.clearDisplay(0);
  result = IRC.read();
  if (result & BLOB1)
  {
    DispX(IRC.Blob1.X);
    DispY(IRC.Blob1.Y);
    Serial.print(IRC.Blob1.X);
    Serial.print(" X:");
    Serial.print(IRC.Blob1.Y);
    Serial.println(" Y:");
  }
  
 // DispY(random(1111,9999));
// DispX(random(1111,9999)); 
//delay(89);


}

void DispY(int Yval)
{
  one=Yval%10;
  ten=(Yval/10)%10;
  hundred=(Yval/100)%10;
  thousand=(Yval/1000)%10;
   mydisplay.setDigit(0,0,(byte)one,0);  // mydisplay.setDigit(addr , digits , value , dp);
   mydisplay.setDigit(0,1,(byte)ten,0);
   mydisplay.setDigit(0,2,(byte)hundred,0);
   mydisplay.setDigit(0,3,(byte)thousand,0);
}
void DispX(int Xval)
{
  one1=Xval%10;
  ten1=(Xval/10)%10;
  hundred1=(Xval/100)%10;
  thousand1=(Xval/1000)%10;
   mydisplay.setDigit(0,4,(byte)one1,0);  // mydisplay.setDigit(addr , digits , value , dp);
   mydisplay.setDigit(0,5,(byte)ten1,0);
   mydisplay.setDigit(0,6,(byte)hundred1,0);
   mydisplay.setDigit(0,7,(byte)thousand1,0);
}
