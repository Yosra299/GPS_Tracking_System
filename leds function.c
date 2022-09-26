#include <D:\!My\Documents\Keil/tm4c123gh6pm.h>
void SystemInit(){};
void wait (void);
//////////////////////////////////////////////////////

// control leds

void leds (int k){
	
	SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for PORTF
	while ((SYSCTL_PRGPIO_R & 0x20)==0) ;  //wait til port F is activated
  GPIO_PORTF_DEN_R  = 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins
  GPIO_PORTF_DIR_R  = 0x0E;  // Configure ORTF Pin1, 2 and 3 digital output pins
	
	if(k==0){
		GPIO_PORTF_DATA_R |= 0x02; // turn on red LED
	}
  if(k==1){
		GPIO_PORTF_DATA_R |= 0x04; // turn on blue LED
	}
  if(k==2){
		GPIO_PORTF_DATA_R |= 0x08; // turn on green LED
	}
	if(k==012){
		GPIO_PORTF_DATA_R |= 0x0E; // turn on all LEDS
	}

} 
