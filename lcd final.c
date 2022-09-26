# GPS_Tracking_System_AAAYYE
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "functions_prototype.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


void delay_milli(int n)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}


	


void LCD_init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x03; // Enable clock for ports
    while((SYSCTL_PRGPIO_R & 0x03)==0){};  //wait til ports are activated
    GPIO_PORTA_DIR_R |=0xE0; //PORTA controls RS,E and R/W
    GPIO_PORTA_DEN_R |=0xE0;
    //portB
    GPIO_PORTB_DIR_R |=0xFF; //PORTB D0-D7
    GPIO_PORTB_DEN_R |=0xFF; //PORTB D0-D7
    //LCD
    LCD_Cmd(0x38); //8-bits,2 display lines, 5x7 font
    LCD_Cmd(0x06); //increments automatically
    LCD_Cmd(0x0F); //Turn on display
    LCD_Cmd(0x01); //clear display
}

void LCD_Cmd(unsigned char command)
{
    GPIO_PORTA_DATA_R = 0x00; //RS=0, E=0, RW=0
    GPIO_PORTB_DATA_R =command;
    GPIO_PORTA_DATA_R = 0x80; //E=1 to secure command
    delay_milli(1);
    GPIO_PORTA_DATA_R =0x00;
    if(command <4)
    {
        delay_milli(2);
    }
    else
    {
        delay_milli(1);
    }
}
void LCD_Data(unsigned char data)
    {
        GPIO_PORTA_DATA_R =0x20; //RS=1, E=0,RW=0
        GPIO_PORTB_DATA_R =data;
        GPIO_PORTA_DATA_R |= 0x80;
        GPIO_PORTA_DATA_R =0x00;
        delay_milli(1);
    }
		
void LCD_GotoXY(uint8_t _x, uint8_t _y)
{
	if(_y)
		_x |= 0x40;
	_x |= 0x80;

	LCD_Cmd(_x);
}
		
void LCD_WriteString(char *_Str)
{
	while(*_Str)
	{
		LCD_Data(*_Str);
		_Str++;
	}
}


void LCD_WriteDouble(double d)
{
	char buf[17];
	sprintf(buf, "%lf",d);
	LCD_WriteString(buf);
}
 
