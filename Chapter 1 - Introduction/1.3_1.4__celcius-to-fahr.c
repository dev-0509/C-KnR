#include<stdio.h>
#include<conio.h>
void main()
{
	int cel = 0, increment = 30, high = 300;
	float fahr;

	printf("\tCelcius to Farenheit Conversion Table\n");
	while(cel <= high)
	{
		fahr = ((cel * 9)/5) + 32;
		printf("%d\t%.3f\n", cel, fahr);
		cel += increment;
	}
}
