double gps_coord_lat (char *gps_data1)
{
    char *gps_data =gps_data1;
   char *crop;
   double latitude;
	 int i;
   crop = strtok(gps_data, ",");
  
	for (i=0;i<=100;i++)
	{
	    
  crop = strtok(NULL, ",");
	    if(i==1)
	    {
	       latitude=convert_string_to_double(crop);

	    }

	}	     
	return (latitude);
}


double gps_coord_long (char *gps_data2)
{
    char *gps_data = gps_data2;
	int j;
   char *crop;
   double longitude;
   crop = strtok(gps_data, ",");
	 for ( j=0;j<=100;j++)
	{
	    
  crop = strtok(NULL, ",");
	    if(j==3)
	    {
	       longitude=convert_string_to_double(crop);
	       

	    }

	}	     
      
	return (longitude);
}


double* GPGGA(char *gps_data)
{
  char *crop1;
  char *crop2;
  double coordinates [2];    
	int i;
	double x,y;
	double true_lat , true_long;
	
    crop1 = strtok(gps_data, "$");
    crop2 = crop1;

         
	for (i=0;i<=100;i++)
	{
	    
        crop1 = strtok(NULL, "$");
	    if(i==17)
	    {

	      printf( " %s\n", crop1 ); 
	     x = gps_coord_lat(crop1);
	     true_lat = true_coord(x);
	     printf( "latitude= %fl \n  ",true_lat );
	      
	    y = gps_coord_long(crop2);
		true_long = true_coord(y);
	   	printf( "longitude= %fl \n",true_long ); 


	    }
	    

	}	
	

	coordinates[0]=true_lat;
	coordinates[1]=true_long;
	return (coordinates);
} 
