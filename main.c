#include <reg51.h>
#include "header.h"
#include <string.h>
sbit buzzer  = P3^7;
sbit trigger = P2^7;
sbit in1=P3^5;
sbit in2=P3^6;
main()
{
	unsigned char master_key[5]="000";
	unsigned char temp=0;
	

		signed int count = 0;
		unsigned char temp1=0,ret1=0,j=0,temp2=0;
		
	//unsigned char *pt;
	char x[5]={0};
	char d[5]={0};
	char b[5]= {0};
const unsigned char * a;
	

	signed char user_id;
	const	unsigned char * read_pass;
	
	buzzer = 0;
	
	init_pass_write_user_one(); /* writing password to the eeprom */
	init_pass_write_user_two(); /* writing password to the eeprom */
	init_pass_write_user_three(); /* writing password to the eeprom */
	
	
	welcome_screen();				         /* Calling welcome Screen function */

	initialize_interrupt();          /* initialize the interupts */
	
	while(1)
	{ 
		
		

		
		user_id = taking_id();          /* selection id from user */
		
		read_pass = select_id(user_id);	/* select one from three id */
		
		strcpy(x , read_pass);
		
		a = enter_password();
		
		ret1=strcmp(a,x); //COMPARE PASS
				
	 if(ret1==0)
	{
				 
				lcd_cmd(0x01);
		   string_data("PASS MATCH");
				
		   lcd_cmd(0xC0);
		   string_data("OPEN DOOR");
				
			 door_open();
		
			 delay_ms(2000);
				 

	}
		   else if((ret1=strcmp(a,master_key))==0)
			 {
				lcd_cmd(0x01);
				lcd_cmd(0x80);
	     string_data("SET YOUR PASSWORD"); 
	      //delay_ms(4000);
	      lcd_cmd(0xC0);
	      string_data("PRESS = KEY");
				delay_ms(400);
	       while(Is_Keypressed());//waiting for sw press
		     temp2=key_Val();
				 
				 trigger = 0;
				 trigger = 1;
			
				 
	       }
		 
		else
		{
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			
		string_data("WRONG PASS");	
		lcd_cmd(0xC0);
		string_data("TRY AGAIN ");
		count++;
		lcd_data(count+48);
		buzzer = 1;
			
		door_close();
		
		buzzer = 0;
			
		password_count(count);
			
		}
					
			
		   
	}
}
