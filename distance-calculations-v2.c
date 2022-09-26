 
#include <math.h>
#define PI   3.14159265358979323846264338327950288
#define R    6371

double distance_m(double lat1, double long1, double lat2,double long2)
{
    // Converting latitudes and longitudes from degree to radian
    double lat1_rad = lat1*(PI/180);
    double long1_rad = long1*(PI/180);
    double lat2_rad = lat1*(PI/180);
    double long2_rad = long1*(PI/180);
     
    // Haversine Formula
    double dlong = long2_rad - long1_rad;
    double dlat = lat2_rad - lat1_rad;
    double ans = pow(sin(dlat / 2), 2) +  cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
	
    // Radius of Earth in Kilometers, R = 6371   
  
    return (ans * R)/1000;
}
