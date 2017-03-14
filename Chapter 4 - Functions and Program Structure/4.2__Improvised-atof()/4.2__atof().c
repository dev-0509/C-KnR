#include "stdio.h"
#include "ctype.h"
#include "math.h"

/*
	Code converts a scientific number given in the form of a character string, into
	a number which is the corresponding Floating Point Representation of the input
	string
*/

#define MAXLENGTH 	100
#define READ 		"r" 

double a_to_f(char string[])
{
	double number, power = 1.0, exponent;
	int index, sign, exponent_sign;

	for( index = 0 ; isspace( string[index] ) ; index++ );		/* Skip Spaces */

	sign = ( string[index] == '-') ? -1 : 1;

	if( string[index] == '+' || string[index] == '-' )
		++index;

	for( number = 0.0 ; isdigit( string[index] ) ; index++ )	/* Get number part */

		number = 10.0 * number + ( string[index] - '0' );

	if( string[index] == '.' )
		++index;

	for( power = 1.0 ; isdigit(string[index]) ; index++ )		/* Get decimal part */
	{
		number = 10.0 * number + ( string[index] - '0' );
		power *= 10.0;
	}

	if( string[index] == 'e' || string[index] == 'E' )			
		++index;

	exponent_sign = ( string[index++] == '-' ) ? -1 : 1;

	for( exponent = 0.0 ; isdigit( string[index] ) ; index++ )	/* Get exponential part */
	
		exponent = 10.0 * exponent + ( string[index] - '0' );

	number *= pow( 10.0 , ( exponent_sign * exponent ) );

	return ( sign * number / power ); 
}

void readString(char * string)
{
	FILE *fptr;
	char newchar;

	char filename[] = "C:\\Users\\devsa\\Desktop\\Study !\\Programs\\C-KnR\\Chapter 4 - Functions and Program Structure\\4.2__Improvised-atof()\\4.2_InputCase.txt";
	
	fptr = fopen ( filename , READ );
	
	if( fptr == NULL ) 
	{
		printf ( "Error: File not found !\n" );
		return;
	}

	while ( ( newchar = fgetc ( fptr ) ) != EOF ) 
		*string++ = newchar;

	*string = '\0';
	
	fclose ( fptr );
}

int main( void )
{
	char string[ MAXLENGTH ];
	double number;

	readString( string );

	number = a_to_f( string );

	printf("\nFloating point representation of the string %s : %lf\n", string, number);

	return 0;
}