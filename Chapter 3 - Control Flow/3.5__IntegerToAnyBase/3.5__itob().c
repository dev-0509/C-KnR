#include "stdio.h"
#include "math.h"
#include "string.h"
#include "Global.h"

void setSign(int sign, char * string)
{
	if( sign == '-' )

		string[i] = sign;
}

char setHexAlphabet(int number)
{
	char initial = 'A';

	if( IS_DIGIT( number - 10 ) )
		return ( initial + (number - 10) );

	else
		return FALSE;
}

void putToString(int number, char string[], int base)
{
	char character, hex = FALSE;

	if( base == 16 )
		hex = TRUE;

	if( number > 9 )
	{
		if( hex == TRUE )
		{
			hex = setHexAlphabet( number );	
		}

		while( number && hex == FALSE )
		{
			character = ( number % 10 ) + '0';

			string[i++] = character;

			character /= 10;
		}
	}

	else
	{
		character = number + '0';

		string[i++] = character;

		return;
	}

	if( hex )
		string[i++] = hex;
}

int convertToBase(int number, int base, char string[])
{
	int int_number;

	int_number = abs( ( number % base ) );

	putToString( int_number , string , base );

	number /= base;

	return number;
}

void itob(int number, char string[], int base)
{
	char sign = 0;

	if( number < 0 )
		sign = '-';

	while( number )

		number = convertToBase( number , base , string );

	setSign( sign , string );

	string[i] = '\0';

	strrev( string );
}

void getInput(int *number, int *base)
{
	printf("\nNumber : ");
	scanf("%d", number);

	printf("\nBase : ");
	scanf("%d", base);
}

int main()
{
	int number, base;
	char string[MAXLENGTH];

	getInput( &number , &base );

	itob( number , string , base );

	printf("\nString Representation of %d in Base %d : %s\n", number, base, string);

	return 0;
}