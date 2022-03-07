# DAC80501

DAC80501 16-bit Arduino library.

An Arduino library for the 16-bit, 1 channel DAC80501 DAC. It should work without change for the DAC70515 and DAC60501 chips.

Extending the library to work with the multi-channel versions of these chips should only require additional bitmap definitions for configuration.

You can find more programming details here: https://www.ti.com/product/DAC80501

I have provided a single example, which has been tested only at 3.3V on ESP32 with no I2C pin reassignments, at 100kHz and 400kHz.

If you like the library it would be cool if you can give it a star. If you find bugs, please inform me. 
