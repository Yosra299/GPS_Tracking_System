#include "hw_timer.h"
#include <inttypes.h>
#include "tm4c123gh6pm.h"


void Systick_Wait_1ms (void)
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 80000-1;   //0x00fffffffff;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R = 0x05;
	while((NVIC_ST_CTRL_R & 0x00010000)==0){}
}	
void Systick_Wait_Multiples_1ms(uint32_t time)
{
	uint32_t j;
	for(j=0;j<time;j++)
	{
		Systick_Wait_1ms();
	}
} 
