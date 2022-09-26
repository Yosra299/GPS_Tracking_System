 
/preprossing
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "tm4c123gh6pm.h"
#include "functions_prototype.h"


//Constants Delecration

#define PI   3.14159265358979323846264338327950288
#define R    6371
//functions prototype
void SystemInit(){};

	
	
//main function
int main(void)
{
	double latitude1 = 40.7128;
	double longitude1 = 74.0095;
	double latitude2 = 51.5074;
	double longitude2 = 0.1278;
	double d ;
	uint32_t x ;
	portF_init();
	
	while(1)
	{
			d = distance_m(latitude1,longitude1,latitude2,longitude2);
			x = portF_input();
			
			 if ( x == 0x10 | x == 0x01 | d<=105 | d>=95 ) 
				{
					portF_output(0x02);
				}					
				else if (x == 0x11)
					{
					portF_output(0x08);	
					}
				else
				{
			  portF_output(0);	
				}
