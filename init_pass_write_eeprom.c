#include"header.h"

void init_pass_write_user_one(void)
{
	  /* password write for user one */
	
	i2c_device_byte_write(0xA0,0x3,'1');
		
	i2c_device_byte_write(0xA0,0x4,'2');
		
	i2c_device_byte_write(0xA0,0x5,'3');
	 
}

void init_pass_write_user_two(void)
{
	
	/* password write for user two */
	
	i2c_device_byte_write(0xA0,0x8,'4');
		
	i2c_device_byte_write(0xA0,0x9,'5');
		
	i2c_device_byte_write(0xA0,0x0A,'6');
	 	
}

void init_pass_write_user_three(void)
{
		
	/* password write for user three */
	
	i2c_device_byte_write(0xA0,0x0D,'7');
		
	i2c_device_byte_write(0xA0,0x0E,'8');
		
	i2c_device_byte_write(0xA0,0x0F,'9');
	
}