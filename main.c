//preprossing
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "tm4c123gh6pm.h"
#include "functions_prototype.h"


void SystemInit(){};	
	
//main function
	
int main(void)
{
	//at first milestone coordinates are hardcooded just to test the led
	double latitude1 =48.1372;
	double longitude1 =11.5756 ;
	double latitude2 =52.5186 ;
	double longitude2 =13.4083;
	double d ;
	
	uint32_t x ;   
	
	//function call for intialization
	portF_init();
	LCD_init();	
	

	//lcd test
	LCD_init();
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	delay_milli(500);
	LCD_GotoXY(3, 0);
	LCD_WriteString("ASU Eng.");
	LCD_GotoXY(3, 1);
	LCD_WriteString("Group 25");
	
	
	//led test with buttons and more than or rqual 100m length
	while(1)
	{
			x = portF_input();
	  	d = distance_m(latitude1,longitude1,latitude2,longitude2);
		if (x == 0x10 || x == 0x01 ||d >=95 ||d<=105)
				{
					portF_output(0x02);
					delay_milli(1000);					
				
				}					
	else if (x == 0x11)
					{
				  portF_output(0x08);	
					delay_milli(1000);	
					
					}
	 else 
				{
			  portF_output(0x00);	
				}
			}
			

} 
