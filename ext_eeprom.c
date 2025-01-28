#include <xc.h>
#include "main.h"
#include "ext_eeprom.h"
#include "i2c.h"

/* 
 * DS1307 Slave address
 * D0  -  Write Mode
 * D1  -  Read Mode
 */

void write_ext_eeprom(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(SLAVE_WRITE1);
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
    for(unsigned int i=3000;i--;);
}

unsigned char read_ext_eeprom(unsigned char address)
{
	unsigned char data;

	i2c_start();
	i2c_write(SLAVE_WRITE1);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(SLAVE_READ1);
	data = i2c_read();
	i2c_stop();

	return data;
}