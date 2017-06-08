#include "stdio.h"
#include "string.h"
#include "Global.h"

/*

=>	Improvised readLines method, reads a particular line of input either from the user or 
	reads from a predefined file.

	Runs efficiently as it does not makes the use of 'alloc' method to check the available
	memory in the system and also, eliminates the use of an extra pointer, as used in the
	explanation of readLines from the book.

Happy Coding! :)

*/

int getLine(char * line) {

	int index = 0;
	char nextchar;

	while( ( index < MAXLENGTH ) && NEW_CHARACTER_EXISTS( nextchar ) )

		line[index++] = nextchar;

	line[index] = '\0';

	return ( strlen( line ) );

}

int readLines(char * line_buffer[], int * line_number) {

	int length;
	char newline[ MAXLENGTH ];

	while( ( length = getLine( newline ) ) > 0 ) {

		if( *line_number > MAXLINES )

			return OVERFLOW;

		line_buffer[ *line_number ] = newline;

		++(*line_number);

	}

}

int main(int argc, char const *argv[]) {

	int line_number = 0;
	char * line_buffer[ MAXLINES ];

	readLines( line_buffer , &line_number );

	return 0;

}