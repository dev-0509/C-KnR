#include "stdio.h"
#include "stdlib.h"
#include "entab.h"

//----------------------------------------------------------- INPUT ----------------------------------------------------------//

char filename[] = "5.11__input.txt";

void fetchTabstopWidth(char const * argv[], int * tabstop_width) {

	*tabstop_width = atoi( argv[ 1 ] );

}

void readInputFromFile(char * string) {

	FILE *fptr;
	char nextchar;

	fptr = fopen( filename , READ );

	if( fptr ) {

		while( ( nextchar = fgetc( fptr ) ) != EOF ) 

			*string++ = nextchar;

	} else

		printf("\nInvalid File");

	*string = '\0';

}

//----------------------------------------------------------------------------------------------------------------------------//


//----------------------------------------------------------- OUTPUT ----------------------------------------------------------//

void displayOutputString(char * output_string) {

	system( "clear" );

	printf("%s\n\n", output_string);

}

//----------------------------------------------------------------------------------------------------------------------------//