#include<stdio.h>
#include<stdlib.h>

int main ()
	{
		char latitude_string[] = "0899.98765";
		char * ptr;
		double latitude_double;
		latitude_double = strtod (latitude_string,&ptr);
		printf ("\nOutput= %.7f\n\n", latitude_double);
		return 0;
	} 
