#include "stdio.h"
#include "string.h"
#include "detab.h"

char getNextChar(char * string) {

	return ( *string );

}					

void sendCharToOutputString(char * output_string, char character) {

	static int index = 0;

	if( character == TAB ) {

		strcat( output_string , "\\t" );

		index += 2;

		output_string[ index ] = END_OF_STRING;

		return;

	}

	output_string[ index++ ] = character;

	output_string[ index ] = END_OF_STRING;

}
