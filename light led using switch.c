#include"F:/EE319Kware/inc/tm4c123gh6pm.h"
#include <stdint.h>
void SystemInit(){};


int main (){
SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for PORTF
	while ((SYSCTL_PRGPIO_R & 0x20)==0);  //wait til port F is activated
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R = 0x1F;    // unlock port F
	GPIO_PORTF_DIR_R  = 0x0E;  // Configure pORTF Pin1, 2 and 3 digital output pins
  GPIO_PORTF_DEN_R  = 0xFF;  // Enable PORTF Pin 0 and 4 as a digital pins
	GPIO_PORTF_PUR_R = 0x11; //Enable pull up for PF0,PF1
	
	while(1){
     switch(GPIO_PORTF_DATA_R & 0x11) // 0x11 = 10001
        {
            case 0x00: //both switches are pressed
            {
                GPIO_PORTF_DATA_R = 0x02; // turn on the red led
                break;
            }
            case 0x01: //SW1 is pressed, SW2 is not pressed
            {
                GPIO_PORTF_DATA_R = 0x04; // turn on the blue led
                break;
            }
            case 0x10: //SW2 is pressed, SW1 is not pressed
            {
                GPIO_PORTF_DATA_R = 0x08; // turn on the green led
                break;
            }
            default:
                GPIO_PORTF_DATA_R = 0;
                break;
        }
	}
} 
