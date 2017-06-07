#include "stdio.h"
#include "string.h"
#include "Global.h"

int getLine(char * line) {

	int index = 0;
	char nextchar;

	while( ( nextchar = getchar() ) != EOI && ( nextchar != NEWLINE ) )

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