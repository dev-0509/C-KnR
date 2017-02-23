#include <stdio.h>

// Function Prototype
float celcius_to_farenheit(int);

int main()
{
	int celcius = 0, increment  = 20, high = 300;
 	
 	while(celcius <= high)
 	{
 		printf("%d  -  %.2f\n", celcius, celcius_to_farenheit(celcius));
 		celcius += increment;
 	}

	return 0;
}

// Function Definition 
float celcius_to_farenheit(int cel)
{
	float farenheit;

	farenheit = ((cel * 9)/5) + 32;

	return farenheit;
}