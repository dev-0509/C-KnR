#include "stdio.h"
#include "stdlib.h"
#include "detab.h"

//---------------------------------------------------------- INPUT ---------------------------------------------------------//

void fetchTabstopWidth(char const * argv[], int * tabstop_width) {

	*tabstop_width = atoi( argv[ 1 ] );

}

char filename[] = "detab_input.txt";

void readInputFromFile(char * string) {

	FILE *fptr;

	char nextchar, status;

	fptr = fopen( filename , READ );

	while( ( nextchar = fgetc( fptr ) ) != EOF ) {

		status = placeTabIfFound( &string , nextchar , fptr );

		if( status == FOUND )

			continue;

		else

			*string++ = nextchar;

	}

	*string = END_OF_STRING;

}

int placeTabIfFound(char ** string, char nextchar, FILE * fptr) {

	if( nextchar == '\\' ) {

		nextchar = fgetc( fptr );

		if( nextchar == 't' ) {

			*( *string )++ = '\t';

			return FOUND;

		}

		else {

			*( *string )++ = '\\';

			*( *string )++ = nextchar;

			return NOT_FOUND;

		}

	}

	return NOT_FOUND;

}

//--------------------------------------------------------------------------------------------------------------------------//


//---------------------------------------------------------- OUTPUT ---------------------------------------------------------//

void displayOutputString(char * output_string) {

	system( "clear" );

	printf("%s\n\n", output_string);

}

//--------------------------------------------------------------------------------------------------------------------------//