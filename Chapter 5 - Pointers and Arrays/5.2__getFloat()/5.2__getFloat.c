#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "Global.h"

/*

=> 	Program to convert a given string of decimal numbers into it's corresponding single
	precision format, i.e., Floating Point Number

*/

void displayResult(char status, double number) {

	if( status == NOT_A_NUMBER )

		printf("Invalid!");

	else

		printf("%f", number);

}

float extractPostDecimalNumber(char string[], double * decimal_places) {

	float number;
	char nextchar;

	for( number = 0.0 , nextchar = get_ch( string ) ; isdigit( nextchar ) ; 

								nextchar = get_ch( string ) ) {

		number = ( number * 10.0 ) + ( nextchar - '0' );

		*decimal_places *= 10.0;

	}

	return number;	

}

float extractPreDecimalNumber(char string[], char nextchar) {

	float number;

	for( number = 0.0 ; isdigit( nextchar ) ; 

						nextchar = get_ch( string ) )

		number = ( number * 10.0 ) + ( nextchar - '0' );

	return number;

}

void convertStringToFloat(char string[], char nextchar, double **target_number) {

	float predecimal_number, postdecimal_number;

	double number, decimal_places = 1.0;

	predecimal_number = extractPreDecimalNumber( string , nextchar );

	postdecimal_number = extractPostDecimalNumber( string , &decimal_places );

	number = ( predecimal_number * decimal_places ) + postdecimal_number;

	**target_number = ( number / decimal_places );

}

int pushNextcharBackIfNotANumber(char character) {

	if( ! isdigit( character ) ) {

		unget_ch( character );

		return IS_CHARACTER;

	}

	return IS_NUMBER;

}

int isWildCharPresent(char character) {

	if( !isdigit( character ) && character != '\0' 

		&& character != '+' && character != '-' )

		return PRESENT;

	else

		return NOT_PRESENT;

}

float getFloat(char string[], double * number) {

	int sign = 1;
	char nextchar;

	if( isWildCharPresent( nextchar = get_ch( string ) ) ) {

		unget_ch( nextchar );

		return NOT_A_NUMBER;

	}

	if( nextchar == '+' || nextchar == '-' ) {

		sign = ( nextchar == '-' ) ? -1 : 1;

		nextchar = get_ch( string );

	}

	if( pushNextcharBackIfNotANumber( nextchar ) ) 

		return NOT_A_NUMBER;

	convertStringToFloat( string , nextchar , &number );

	*number *= sign;

	return SUCCESS;

}

void getStringFromCmd(char const * argv[], char * string) {

	strcpy( string , argv[ 1 ] );

}

int main(int argc, char const * argv[]) {

	double target_number;
	char string[ MAXLENGTH ], status;
	
	getStringFromCmd( argv , string );

	status = getFloat( string , &target_number );

	displayResult( status , target_number );
	
	return 0;

}

// ------ Global Variable only accessible by get_ch() and unget_ch() ------//
int stringindex;

char get_ch(char string[]) {

	if( stringindex >= 0 )

		return string[ stringindex++ ];

}

void unget_ch(char c) {

	if( stringindex < MAXLENGTH )

		stringindex--;

}