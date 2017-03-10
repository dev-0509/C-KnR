#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "math.h"

#define MAXLENGTH 100	

void itoa(int number, char string[])
{
	int index = 0;
	char sign = 0;

	if( number < 0 )
		sign = '-';

	do
	{	
		string[index++] = ( abs( (number % 10) ) + '0');

		number /= 10;

	} while( number );

	if( sign )
		string[index++] = sign;

	string[index] = '\0';

	strrev( string );
}

int main()
{
	int number;
	char string[MAXLENGTH];

	printf("Enter the number : ");
	scanf("%d" ,&number);

	itoa( number , string );

	printf("\nString conversion successfull : ");
	puts( string );

	return 0;
}