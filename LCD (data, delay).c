#include"F:/EE319Kware/inc/tm4c123gh6pm.h"
#include <stdint.h>
void SystemInit(){};
void delay_milli(int n)
	{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}

	}
	
	
void delay_micro(int n)
	{

		int i,j;

		for(i=0;i<n;i++)

		for(j=0;j<3;j++){}

	}
void LCD_Data(unsigned char data) 
	{
		GPIO_PORTA_DATA_R =0x20; //RS=1, E=0,RW=0
		GPIO_PORTA_DATA_R =data;
		GPIO_PORTA_DATA_R |= 0x80;
		GPIO_PORTA_DATA_R =0x00;
		delay_micro(0);
	} 
