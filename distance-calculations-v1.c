

//define area

#include <stdbool.h> #include <stdint.h> #include <stdio.h> #include <stdlib.h> #include <inttypes.h> #include <string.h> #include "tm4c123gh6pm.h" #include <math.h> #include "ports intialization.h" #define M_PI 3.14159265358979323846264338327950288

////////////////////////////////////////////////////////

//functions area

//gps connection function void gps_conn() {

}

float conversion (float lat , float lon ) { lat = lat * (180 / M_PI); lon = lon * (180 / M_PI); float x = sin(M_PI/2-lat) * cos(lon); float y = sin( M_PI/2-lat) * sin(lon); float z = cos( M_PI/2-lat); float R=sqrt(xx+yy+z*z); return R ; };

float distance (float lat , float lon ) { float difference =0.0 ; float arr[30]; int no_readings = 30; for ( int i =0 ; i<no_readings ; i++) { arr[i] = conversion ( lat , lon ) ; }; for (int i=0; i<10 ; i++) { difference = arr[i] - arr[0] ; }; if (difference >=90 | difference <= 110) { //function led }; };

void lcd_display(){

};

int main() { init(); while(1){

}

}
 
