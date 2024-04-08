#ifndef DAC80501_H_
#define DAC80501_H_
// FILE: DAC80501.h
// AUTHOR: Richard Palmer - Rob Tillaart's ADS1X15 library was used as a template
// PURPOSE: Arduino library for DAC80501 SPI Digital Analog Convertor

#include "Arduino.h"
#include "Wire.h"

#include "DAC80501defs.h"
#ifndef ADS1015_ADDRESS
#define ADS1015_ADDRESS   DAC80501_ADDR_LOW
#endif

#define MODE_3V3 (DAC80501_GAIN_REF_DIV_MASK | DAC80501_GAIN_BUFF)

class DAC80501
{
public:
  DAC80501(uint8_t i2cAddr);
  DAC80501(uint8_t i2cClock, uint8_t i2cAddr);

  bool     begin();
  void 	   softReset(void);

  uint16_t getDevID();		// device specs
  bool 	   isConnected();
  
  void     setValue(uint16_t value);
  uint16_t getValue();
  // for multi-channel chips
  void     setValue(uint16_t value, uint8_t chan);
  uint16_t getValue(uint8_t chan);
  
  // set to MODE_3V3 if VDD = 3.3V
  void     setGain(uint16_t value);
  uint16_t getGain() { return getReg(DAC80501_GAIN_ADDRESS);}  
  
  void     setConf(uint16_t value);
  uint16_t getConf() { return getReg(DAC80501_CONFIG_ADDRESS);}  
  
  void 	   setSync(bool syn);	// set LDAC SYNC mode
  uint16_t getSync() { return getReg(DAC80501_SYNC_ADDRESS);} 
  
  void     setTrig(bool trig);	// need to set this when in LDAC SYNC mode after each setValue()
  uint16_t getTrig() { return getReg(DAC80501_TRIGGER_ADDRESS);} 
  
  //       speed in Hz
  void     setI2Cspeed(uint32_t speed);
  uint32_t getI2Cspeed() { return _I2Cspeed; };
  
  uint16_t getReg(uint8_t reg);


private:
  uint8_t  _addr     = 255;
  uint32_t _I2Cspeed    = 400000;
  bool     setReg(uint8_t cmd, uint16_t data);  
  TwoWire*  _wire;
};

#endif