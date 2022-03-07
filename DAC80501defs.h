/* register definitions for the DAC80501 */
/* removed DAC_B definitions */

#ifndef DAC80501D_H_
#define DAC80501D_H_

#define DAC80501_ADDR_LOW	0x48
#define DAC80501_ADDR_HIGH	0x49
#define DAC80501_ADDR_SDA	0x50
#define DAC80501_ADDR_SCL	0x51

/* NOOP register address */
#define DAC80501_NOOP_ADDRESS						((uint8_t) 0x00)
/* NOOP default (reset) value */
#define DAC80501_NOOP_DEFAULT						((uint16_t) 0x0000)
/* NOOP register field masks */
#define DAC80501_NOOP_MASK							((uint16_t) 0x0001)

/* DEVID register address */
#define DAC80501_DEVID_ADDRESS						((uint8_t) 0x01)
/* DEVID default (reset) value */
#define DAC80501_DEVID_DEFAULT						((uint16_t) 0x0000)
/* DEVID register field masks */
#define DAC80501_DEVID_RESOLUTION_MASK				((uint16_t) 0x7000)

/* SYNC register address */
#define DAC80501_SYNC_ADDRESS						((uint8_t) 0x02)
/* SYNC default (reset) value */
#define DAC80501_SYNC_DEFAULT						((uint16_t) 0x0300)
/* SYNC register field masks */
//#define SYNC_DAC-B-BRDCAST-EN_MASK				((uint16_t) 0x0200)
#define DAC80501_SYNC_EN							((uint16_t) 0x0100)
// #define SYNC_DAC-B-SYNC-EN_MASK					((uint16_t) 0x0002)
#define DAC80501_SYNC_EN_MASK						((uint16_t) 0x0001)

/* CONFIG register address */
#define DAC80501_CONFIG_ADDRESS						((uint8_t) 0x03)
/* CONFIG default (reset) value */
#define DAC80501_CONFIG_DEFAULT						((uint16_t) 0x0000)
/* CONFIG register field masks */
#define DAC80501_CONFIG_REF_PWDWN_MASK				((uint16_t) 0x0100)
// #define CONFIG_DAC-B-PWDWN_MASK					((uint16_t) 0x0002)
#define DAC80501_CONFIG_DAC_PWDWN_MASK				((uint16_t) 0x0001)

/* GAIN register address */
#define DAC80501_GAIN_ADDRESS						((uint8_t) 0x04)
/* GAIN default (reset) value */
#define DAC80501_GAIN_DEFAULT						((uint16_t) 0x0003)
/* GAIN register field masks */
#define DAC80501_GAIN_REF_DIV_MASK					((uint16_t) 0x0100)
//#define GAIN_BUFF-B -GAIN_MASK					((uint16_t) 0x0002)
#define DAC80501_GAIN_BUFF 							((uint16_t) 0x0001)

/* TRIGGER register address */
#define DAC80501_TRIGGER_ADDRESS					((uint8_t) 0x05)
/* TRIGGER default (reset) value */
#define DAC80501_TRIGGER_DEFAULT					((uint16_t) 0x0000)
/* TRIGGER register field masks */
#define DAC80501_TRIGGER_LDAC_MASK					((uint16_t) 0x0010)
#define DAC80501_TRIGGER_SOFT_RESET_MASK			((uint16_t) 0x000F)
#define DAC80501_TRIGGER_SOFT_RESET					((uint16_t) 0x000A)

#define DAC80501_STATUS_ADDRESS						((uint8_t) 0x07)

#define DAC80501_DATA_ADDRESS						((uint8_t) 0x08)

#endif /* DAC80501D_H_ */
