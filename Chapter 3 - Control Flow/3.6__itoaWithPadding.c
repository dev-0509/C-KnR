#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "math.h"

#define MAXLENGTH 		100	
#define FIELD_WIDTH 	8

void itoa(int number, char string[], int field_width)
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
		string[index] = sign;

	while( index < field_width )
		string[index++] = ' ';

	string[index] = '\0';

	strrev( string );
}

int main()
{
	int number, field_width;
	char string[MAXLENGTH];

	printf("Enter the number : ");
	scanf("%d" ,&number);

	itoa( number , string , FIELD_WIDTH );

	printf("\nString conversion successfull :- \n\t\t\t\t |");
	puts( string );

	return 0;
}