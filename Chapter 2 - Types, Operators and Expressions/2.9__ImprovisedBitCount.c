#include "stdio.h"

int gNumber, gCount;
int number;

void getInput()
{
	printf("\nNumber : ");

	scanf("%d", &number);

	gNumber = number;
}

int calculateCountOfSetBits()
{
	int no_of_bits = 0;

	while(number != 0)
	{
		number &= ( number - 1 );

		++no_of_bits;
	}

	return no_of_bits;
}

int main()
{
	getInput();

	gCount = calculateCountOfSetBits();

	printf("\nNumber of Bits Set in %d : %d\n", gNumber, gCount);

	return 0;
}