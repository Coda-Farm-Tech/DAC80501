// I2C Scan and DAC 80501 test
// Only tested on ESP32
// RP 2022
#define I2CSPEED  4000000  
#define I2Caddr 0x48
#include <Wire.h>
#include "DAC80501.h"
DAC80501 dac(I2Caddr);

void setup() {      
  Serial.begin (115200);
  while (!Serial) 
    ;
  delay(2000);
  Serial.println ("DAC80501 staircase test");
  Wire.begin(); 
  Wire.setClock(I2CSPEED);
  I2Cscan();
  delay (100);
  dac.begin();  
  dac.setGain(MODE_3V3); 
  dac.setValue(50); // a non-zero value for printRegs() to return
  printRegs();
  Serial.println ("Done setup");
}  

uint16_t dacVal = 0;
#define INCR (65536 / 20)
#define COUNTS 65536

void loop() {
  dac.setValue(dacVal);
  dacVal = (dacVal + INCR) % COUNTS;
  Serial.printf("Set %i, get %i\n",dacVal, dac.getValue());
  delay(1000);
}

bool I2Cscan(void)
{       
  int count = 0;
  Serial.println ("I2C scanner");
  for (uint8_t i = 1; i < 127; i++) // 8 to 120 are legal
  {
    Wire.beginTransmission (i); 
    if (Wire.endTransmission () == 0)
      {
        Serial.print ("- Found address: ");  
        Serial.print ("0x");
        Serial.println (i, HEX);
        delayMicroseconds(50);  
        count++; 
      }      
  } 
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s)\n");
  return (count > 0);
}

void printRegs()
{
    Serial.printf("DEVID 0x%04x \n",dac.getReg(1));
    Serial.printf("SYNC  0x%04x \n",dac.getReg(2));
    Serial.printf("CONF  0x%04x \n",dac.getReg(3));
    Serial.printf("GAIN  0x%04x \n",dac.getReg(4));
    Serial.printf("TRIG  0x%04x \n",dac.getReg(5));
    Serial.printf("STAT  0x%04x \n",dac.getReg(7));
    Serial.printf("DATA  0x%04x \n",dac.getReg(8));

}
