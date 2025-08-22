#ifndef APP_API_H
#define APP_API_H

#include <reg51.H>   /* or your exact device: REGX51.H / AT89X51.h etc. */

/* --- I2C / LCD / etc prototypes --- */

extern void welcome_screen(void);        /* Welcome Screen */

extern void initialize_interrupt(void);  /* Initialize Interrupt */

extern void I2C_Start();

extern void I2C_Stop();

extern void I2C_Byte_Write(unsigned char dat);

extern unsigned char I2C_Byte_Read();

extern void I2C_Slave_Ack();

extern void I2C_Noack();

extern void I2C_Master_Ack();

extern void I2C_Device_Byte_Write(unsigned char sa,unsigned char buf_addr,unsigned char dat);

extern unsigned char I2C_Device_Byte_Read(unsigned char sa,unsigned char buf_addr);

extern void I2C_Device_Seq_Write(unsigned char sa,unsigned char buf_addr,unsigned char dat);

extern unsigned char I2C_Device_Seq_Read(unsigned char sa,unsigned char buf_addr);

extern void I2C_Byte_Write_Frame(unsigned char sa,unsigned char mr,unsigned char d);

extern void lcd_data(unsigned char  d);

extern void lcd_cmd(unsigned char c);

extern void lcd_init(void);

extern void string_data(unsigned char *d);

extern void delay_ms(unsigned int ms);

extern void row_Init(void);

extern bit Is_Keypressed(void);

extern char key_Val(void);

extern unsigned int cmp(const char *,const char *);

extern void init_pass_write(void);

extern unsigned char* init_pass_read(void);

extern void edit_pass(void);

extern unsigned char * init_pass_read_1(void);

extern signed char taking_id(void);

extern const unsigned char * select_id(signed char); 

extern void init_pass_write_user_one(void);

extern void init_pass_write_user_two(void);

extern void init_pass_write_user_three(void);

extern unsigned char * init_pass_read_user_one(void);

extern unsigned char * init_pass_read_user_two(void);

extern unsigned char * init_pass_read_user_three(void);

extern unsigned char * enter_password(void);

extern void compare_password(unsigned char*, unsigned char*);

extern void door_open(void);

extern void door_close(void);

extern void password_count(signed int);

#endif /* APP_API_H */