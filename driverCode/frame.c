// #include "../include/app_api.h"
// void I2C_Byte_Write_Frame(unsigned char sa,unsigned char mr,unsigned char d)
// {
// bit ret;
// i2c_start();
// i2c_write(sa);
// ret=i2c_ack();
// if(ret==1)
// goto out;
// i2c_write(mr);
// ret=i2c_ack();
// if(ret==1)
// goto out;
// i2c_write(d);
// ret=i2c_ack();
// if(ret==1)
// goto out;
// out:
// i2c_stop();
// }



// // unsigned char I2C_Byte_Read_frame(unsigned char sa,unsigned char mr)
// // {
// // unsigned temp; 
// // bit ret;
// // I2C_Start();
// // I2C_Byte_Write(sa);
// // ret=i2c_ack();
// // if(ret==1)
// // goto out;
// // I2C_Byte_Write(mr);
// // ret=i2c_ack();
// // if(ret==1)
// // goto out;
// // I2C_Start();
// // I2C_Byte_Write(sa|1);
// // ret=i2c_ack();
// // if(ret==1)
// // goto out;
// // temp=i2c_read();
// // I2C_Noack();
// // out:
// // i2c_stop();
// // return temp;
// // }
