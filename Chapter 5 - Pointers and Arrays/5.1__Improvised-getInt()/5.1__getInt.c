#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"	
#include "Global.h"

/*--------------------------------------------------------------------------------------*\ 

=> Program to convert a numeric String into it's corresponding Integer Number

	Improvised version as it deals with an extra character which is read from the input
	in case the character after the 'sign' is not a number.

	Eg: In String - +abc, the character after '+' is 'a', which is not a number

		But, the earlier version of getInt() read 'a' but never pushed it back but it is
		essential to push it back because 'a' is of no use in number computation.

*\--------------------------------------------------------------------------------------*/


int main(int argc, char const * argv[]) {

	int status, target_number;
	char string[ MAXLENGTH ];

	getStringFromCmd( argc , argv , string );

	status = getInt( string , &target_number );

	if( status == NOT_A_NUMBER )

		displayResult( status , NO_NUMBER );

	else

		displayResult( status , target_number );

	return 0;

}

int isWildCharacterPresent(char character) {

	if( !isdigit( character ) && character != '\0' 

		&& character != '+' && character != '-' )

		return PRESENT;

	else

		return NOT_PRESENT;

}

int pushCharBackIfNotANumber(char character) {

	if( ! isdigit( character ) ) {

		unget_ch( character );

		return 0;

	}

}

int convertStringToNumber(char string[], char nextchar, int **target_number) {

	for( **target_number = 0 ; 

			isdigit( nextchar ) ; 	nextchar = get_ch( string ) ) 

		**target_number = ( **target_number * 10 ) + ( nextchar - '0' );

}

int getInt(char string[], int * number) {

	char nextchar, sign;

	while( isspace( nextchar = get_ch( string ) ) ) ;

	if( isWildCharacterPresent( nextchar ) ) {

		unget_ch( nextchar );

		return 0;

	}

	sign = ( nextchar == '-' ) ? -1 : 1;

	if( nextchar == '+' || nextchar == '-' ) 

		nextchar = get_ch( string );

	pushCharBackIfNotANumber( nextchar );

	convertStringToNumber(string , nextchar , &number);

	*number *= sign;

	if( nextchar != '\0' )

		unget_ch( nextchar );

	return *number;

}

int stringindex;

void getStringFromCmd(int argc, char const * argv[], char string[]) {

	strcpy( string , argv[ 1 ] );

}

char get_ch(char string[]) {

	if( stringindex >= 0 )

		return string[ stringindex++ ];

}

void unget_ch(char c) {

	if( stringindex < MAXLENGTH )

		stringindex--;

}

void displayResult(int status, int number)
{
	if( status == NOT_A_NUMBER )
		printf("Invalid");

	else
		printf("%d", number);
}