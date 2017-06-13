#include "stdio.h"
#include "stdlib.h"
#include "entab.h"

//---------------------------------------------------------- INPUT ---------------------------------------------------------//

void fetchTabstopWidth(char const * argv[], int * tabstop_width) {

	*tabstop_width = atoi( argv[ 1 ] );

}

char filename[] = "entab_input.txt";

void readInputFromFile(char * string) {

	FILE *fptr;
	char nextchar;

	fptr = fopen( filename , READ );

	if( fptr ) {

		while( ( nextchar = fgetc( fptr ) ) != EOF ) 

			*string++ = nextchar;

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