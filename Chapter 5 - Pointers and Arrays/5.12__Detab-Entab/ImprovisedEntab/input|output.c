#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "entab.h"

//---------------------------------------------------------- INPUT ---------------------------------------------------------//

void fetchTabSpecifications(char const * argv[], int * tabstop_width, int * start_column) {

	if( ! ( strcmp( argv[ 1 ] , "+tabwidth" ) ) )

		*tabstop_width = atoi( argv[ 2 ] );

	else

		*tabstop_width = TABSTOP;	/* Set TAB width with default width if no cmd arg. is encountered */		

	if( ! ( strcmp( argv[ 3 ] , "-column" ) ) )

		*start_column = atoi( argv[ 4 ] );

	else

		*start_column = 0;

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

	//system( "clear" );

	printf("%s\n\n", output_string);

}

//--------------------------------------------------------------------------------------------------------------------------//