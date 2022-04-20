#include "header.h"

signed char taking_id(void)
{
	unsigned char user_id = 0;
	
		lcd_cmd(0x01);   					/* clear screen */
		lcd_cmd(0x80);	 					/* Select first row */
	  string_data("SELECT ID"); /* sending data to lcd */
	  lcd_cmd(0xC0);
		string_data("FROM 1 2 3"); 
		delay_ms(900);						/* delay for two second */
	
		
		lcd_cmd(0x01);   					/* clear screen */
		lcd_cmd(0x80);	 					/* Select first row */
	  string_data("ENTER ID"); 	/* sending data to lcd */
		delay_ms(100);      		  /* optional */
	
		row_Init();//Row initialization
		
		while(Is_Keypressed());//waiting for sw press
		user_id =	key_Val();		/* storing user id to variable */
		lcd_cmd(0xC0);					/* set curser to second line */
		lcd_data(user_id);     /* display id to lcd */
		delay_ms(1000);
		return user_id;
		

}