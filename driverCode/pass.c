#include "../include/app_api.h"

// Example: write '1'..'5' to EEPROM and read back into b[]
void pass_write_read_demo(void)
{
    unsigned char temp;
    unsigned char b[5];

    I2C_Device_Byte_Write(0xA0, 0x03, '1');
    temp = I2C_Device_Byte_Read(0xA0, 0x03); b[0] = temp;

    I2C_Device_Byte_Write(0xA0, 0x04, '2');
    temp = I2C_Device_Byte_Read(0xA0, 0x04); b[1] = temp;

    I2C_Device_Byte_Write(0xA0, 0x05, '3');
    temp = I2C_Device_Byte_Read(0xA0, 0x05); b[2] = temp;

    I2C_Device_Byte_Write(0xA0, 0x06, '4');
    temp = I2C_Device_Byte_Read(0xA0, 0x06); b[3] = temp;

    I2C_Device_Byte_Write(0xA0, 0x07, '5');
    temp = I2C_Device_Byte_Read(0xA0, 0x07); b[4] = temp;

    // use b[] or return via another API as you need
}
