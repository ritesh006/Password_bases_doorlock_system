#include"../include/app_api.h"

void init_pass_write_user_one(void)
{
	  /* password write for user one */
	
	I2C_Device_Byte_Write(0xA0,0x3,'0');
		
	I2C_Device_Byte_Write(0xA0,0x4,'0');
		
	I2C_Device_Byte_Write(0xA0,0x5,'1');
	 
}

void init_pass_write_user_two(void)
{
	
	/* password write for user two */
	
	I2C_Device_Byte_Write(0xA0,0x8,'0');
		
	I2C_Device_Byte_Write(0xA0,0x9,'1');
		
	I2C_Device_Byte_Write(0xA0,0x0A,'0');
	 	
}

void init_pass_write_user_three(void)
{
		
	/* password write for user three */
	
	I2C_Device_Byte_Write(0xA0,0x0D,'1');
		
	I2C_Device_Byte_Write(0xA0,0x0E,'0');
		
	I2C_Device_Byte_Write(0xA0,0x0F,'0');
	
}