#include <reg51.h>
#include "../include/app_api.h"

void initialize_interrupt(void)
{
	
	IE=0x81;
	EA=EX0=1;
  IT0=1;
	
}