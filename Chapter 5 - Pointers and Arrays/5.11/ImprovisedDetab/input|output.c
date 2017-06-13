#include "stdio.h"
#include "stdlib.h"
#include "detab.h"

//---------------------------------------------------------- INPUT ---------------------------------------------------------//

char filename[] = "detab_input.txt";

void fetchTabstopWidth(char const * argv[], int * tabstop_width) {

	*tabstop_width = atoi( argv[ 1 ] );

}

void readInputFromFile(char * string) {

	FILE *fptr;
	char nextchar;

	fptr = fopen( filename , READ );

	if( fptr ) {

		while( ( nextchar = fgetc( fptr ) ) != EOF ) {

			if( nextchar == '\\' ) {

				nextchar = fgetc( fptr );

				if( nextchar == 't' )

					*string++ = '\t';

				else {

					*string++ = '\\';

					*string++ = nextchar;

				}

				continue;

			}

			*string++ = nextchar;

		}

	} else

		printf("\nInvalid File");

	*string = END_OF_STRING;

}

//--------------------------------------------------------------------------------------------------------------------------//


//---------------------------------------------------------- OUTPUT ---------------------------------------------------------//

void displayOutputString(char * output_string) {

	system( "clear" );

	printf("%s\n\n", output_string);

}

//--------------------------------------------------------------------------------------------------------------------------//