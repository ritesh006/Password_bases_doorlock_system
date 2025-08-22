#include<reg51.h>
#include"../include/app_api.h"
//#include"types.h"
sbit sda=P2^4;
sbit scl=P2^5;



void I2C_Stop(void)
{
	scl=0;
	sda=0;
	scl=1;
	sda=1;
}
void I2C_Byte_Write(unsigned char dat)
{
	signed char i;
	for(i=7;i>=0;i--)
	{
		scl=0;
		sda=((dat>>i)&1);
		scl=1;
	}
}
unsigned char I2C_Byte_Read(void)
{
	unsigned char ch=0;
	signed char i;
	for(i=7;i>=0;i--)
	{
		scl=0;
		scl=1;
		if(sda==1)		
		ch|=1<<i;//updating bit status to ch variable
	}
	return ch;
}
void I2C_Slave_Ack(void)
{
	scl=0;
	sda=1;
	scl=1;
	while(sda==1);//waiting
}
void I2C_Noack(void)
{
	scl=0;
	sda=1;
	scl=1;
}
void I2C_Master_Ack(void)
{
	scl=0;//Master making the scl line low
	sda=0;//master pulling the sda line low
	scl=1;
	scl=0;//Master has applied the clock pulse
	sda=1;//Master releasing the sda line 
}
void I2C_Device_Byte_Write(unsigned char sa,unsigned char buf_addr,unsigned char dat)
{
	I2C_Start();
	I2C_Byte_Write(sa);
	I2C_Slave_Ack();			
	I2C_Byte_Write(buf_addr);
	I2C_Slave_Ack();			
	I2C_Byte_Write(dat);
	I2C_Slave_Ack();			
	I2C_Stop();
	delay_ms(10);
}
unsigned char I2C_Device_Byte_Read(unsigned char sa,unsigned char buf_addr)
{
	unsigned char ch;
	I2C_Start();
	I2C_Byte_Write(sa);
	I2C_Slave_Ack();			
	I2C_Byte_Write(buf_addr);
	I2C_Slave_Ack();			
	I2C_Start();
	I2C_Byte_Write(sa|0x01);
	I2C_Slave_Ack();
	ch=I2C_Byte_Read();
	
	I2C_Noack();				
	I2C_Stop();
	delay_ms(10);
	return(ch);
}
/*void I2C_Device_Seq_Write(unsigned char sa,unsigned char buf_addr,unsigned char dat)
{
	unsigned char i;
	I2C_Start();
	I2C_Byte_Write(sa);
	I2C_Slave_Ack();			
	I2C_Byte_Write(buf_addr);
	I2C_Slave_Ack();
	for(i=1;i<9;i++)			
	{
		I2C_Byte_Write(dat+i);
		I2C_Slave_Ack();			
	}
	I2C_Stop();
	delay_ms(10);
}
unsigned char* I2C_Device_Seq_Read(unsigned char sa,unsigned char buf_addr)
{
	unsigned char a[10],i;
	I2C_Start();
	I2C_Byte_Write(sa);
	I2C_Slave_Ack();			
	I2C_Byte_Write(buf_addr);
	I2C_Slave_Ack();			
	I2C_Start();
	I2C_Byte_Write(sa|0x01);
	I2C_Slave_Ack();
	for(i=0;i<7;i++)
	{
		a[i]=I2C_Byte_Read();
		I2C_Master_Ack();
	}
	a[i]=I2C_Byte_Read();
	I2C_Noack();				
	I2C_Stop();
	delay_ms(10);
	return(a);
}

*/
void I2C_Start(void)
{
	scl=0;
	sda=1;
	scl=1;
	sda=0;
}
