#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "detab.h"

//---------------------------------------------------------- INPUT ---------------------------------------------------------//

char filename[] = "detab_input.txt";

void fetchTabSpecifications(char const * argv[], int * tabstop_width, int * start_column) {

	if( ! ( strcmp( argv[ 1 ] , "-tabwidth" ) ) )

		*tabstop_width = atoi( argv[ 2 ] );

	else

		*tabstop_width = TABSTOP;	/* Set TAB width with default width if no cmd arg. is encountered */		

	if( ! ( strcmp( argv[ 3 ] , "-column" ) ) )

		*start_column = atoi( argv[ 4 ] );

	else

		*start_column = 0;

}

void readInputFromFile(char * string, int start_column) {

	FILE *fptr;

	char nextchar;
	int column_no = 0;

	fptr = fopen( filename , READ );

	while( ( nextchar = fgetc( fptr ) ) != EOF ) {

		++column_no;

		if( column_no >= start_column ) {

			placeTabIfFound( &string , nextchar , fptr );

			continue;

		}

		else

			*string++ = nextchar;

	}

	*string = END_OF_STRING;

}

void placeTabIfFound(char ** string, char nextchar, FILE * fptr) {

	if( nextchar == '\\' ) {

		nextchar = fgetc( fptr );

		if( nextchar == 't' )

			*( *string )++ = '\t';

		else {

			*( *string )++ = '\\';

			*( *string )++ = nextchar;

		}

	}

	else

		*( *string )++ = nextchar;

}

//--------------------------------------------------------------------------------------------------------------------------//


//---------------------------------------------------------- OUTPUT ---------------------------------------------------------//

void displayOutputString(char * output_string) {

	system( "clear" );

	printf("%s\n\n", output_string);

}

//--------------------------------------------------------------------------------------------------------------------------//