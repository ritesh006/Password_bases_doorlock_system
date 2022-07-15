#include <reg51.h>
#include "header.h"


unsigned char * enter_password(void)
{
		unsigned char a[5] = {0};
		unsigned char i,temp1 = 0;
	
		lcd_init();
		lcd_cmd(0x01);
		lcd_cmd(0x80);
	  string_data("ENTER PASS"); 
			
		delay_ms(100);
		lcd_cmd(0xC0);
			
		for(i=0;i<3;i++)
		  {
				row_Init();//Row initialization
				while(Is_Keypressed());//waiting for sw press
				temp1=	key_Val();
				a[i]=temp1;
				lcd_cmd(0xC0+i);
				lcd_data(temp1);
					delay_ms(100);
					lcd_cmd(0xC0+i);
					lcd_data('*');
			} 
				a[i]='\0';
				
				delay_ms(300);
			
							
	
		return a;
}