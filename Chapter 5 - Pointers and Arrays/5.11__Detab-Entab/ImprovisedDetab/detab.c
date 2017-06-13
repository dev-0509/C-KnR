#include "stdio.h"
#include "detab.h"

void detab(char * string, char * output_string, int tabstop_width) {

	int charcount = 0;
	char nextchar = 'a';

	while( nextchar != END_OF_STRING ) {

		nextchar = getNextChar( string++ );

		charcount++;

		if( nextchar == TAB )

			placeSpacesToTab( output_string , tabstop_width , &charcount );

		else {

			resetCharCount( &charcount , tabstop_width );

			sendCharToOutputString( output_string , nextchar );

		}

	}

}

void placeSpacesToTab(char * output_string, int tabstop_width, int * charcount) {

	int no_of_spaces;

	no_of_spaces = tabstop_width - ( *charcount - 1 );

	while( no_of_spaces ) {

		sendCharToOutputString( output_string , SPACE );

		--no_of_spaces;

	}

	*charcount = 0;

}

void resetCharCount(int * charcount, int tabstop_width) {

	if( *charcount >= tabstop_width )

		*charcount = 0;

}