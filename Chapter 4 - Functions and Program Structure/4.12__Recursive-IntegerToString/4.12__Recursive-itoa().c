#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"

#define MAXLENGTH 100	

void itoa (int number, char string[])
{
	static int index = 0;

	if ( number == 0 ) {

		return;

	} else {

		itoa ( number / 10 , string );

	}

	string[index++] = ( abs ( (number % 10) ) + '0');

	string[index] = '\0';
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