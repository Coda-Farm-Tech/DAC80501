//
// FILE: DAC80501.cpp
// AUTHOR: Richard Palmer - Rob Tillaart's DAC805011 SPI code was used as a base
// PURPOSE: Arduino library for DAC80501 SPI Digital Analog Convertor


#include "DAC80501.h"


DAC80501::DAC80501(uint8_t i2cAddr)
{
	_addr  = i2cAddr;
	// default speed, gain, powerdown
}


DAC80501::DAC80501(uint8_t i2cClock, uint8_t i2cAddr)
{
  _I2Cspeed   = i2cClock;
  _addr  = i2cAddr;
}


// initializes I2C
// and sets internal state
bool DAC80501::begin()
{
  _wire = &Wire;
  _wire->begin();
  setConf(0);	// assumes internal ref is being used
  //softReset();
  //delay(10);
  if (! isConnected()) return false;
  return true;
}

bool DAC80501::isConnected()
{
  _wire->beginTransmission(_addr);
  return (_wire->endTransmission() == 0);
}

// value = 0..65535
void DAC80501::setValue(uint16_t value)
{
  setReg(DAC80501_DATA_ADDRESS, value);
}
// for multi-channel chips
void DAC80501::setValue(uint16_t value, uint8_t chan)
{
  setReg(DAC80501_DATA_ADDRESS + chan, value);
}

// returns 0..65535
uint16_t DAC80501::getValue()
{
  return getReg(DAC80501_DATA_ADDRESS);
}

uint16_t DAC80501::getValue(uint8_t chan)
{
  return getReg(DAC80501_DATA_ADDRESS + chan);
}

void DAC80501::setGain(uint16_t value)
{
  setReg(DAC80501_GAIN_ADDRESS, value);
}

void DAC80501::setSync(bool syn)
{
	 setReg(DAC80501_SYNC_ADDRESS, (syn)? 1 : 0);
}

void DAC80501::setConf(uint16_t value)
{
	 setReg(DAC80501_CONFIG_ADDRESS, value);
}

void DAC80501::setTrig(bool trig)
{
	 setReg(DAC80501_CONFIG_ADDRESS, (trig) ? 0x10 : 0);
}

void DAC80501::softReset(void)
{
	 setReg(DAC80501_TRIGGER_ADDRESS, DAC80501_TRIGGER_SOFT_RESET);
}

void DAC80501::setI2Cspeed(uint32_t speed)
{
  _I2Cspeed = speed;  
};

uint16_t DAC80501::getReg(uint8_t reg)
{
  _wire->setClock(_I2Cspeed);
  _wire->beginTransmission(_addr);
  _wire->write(reg);
  _wire->endTransmission();

  int rv = _wire->requestFrom((int) _addr, (int) 2);
  if (rv == 2)
  {
    uint16_t value = _wire->read() << 8;
    value += _wire->read();
    return value;
  }
  return 0x0000;
}

//////////////////////////////////////////////////////////////////
//
// PRIVATE
//
bool DAC80501::setReg(uint8_t cmd, uint16_t value)
{
  _wire->setClock(_I2Cspeed);
  _wire->beginTransmission(_addr);
  _wire->write((uint8_t)cmd);
  _wire->write((uint8_t)(value >> 8));
  _wire->write((uint8_t)(value & 0xFF));
  return (_wire->endTransmission() == 0);
}


// -- END OF FILE --