#include "stdio.h"
#include "entab.h"

void entab(char * string, char * output_string, int tabstop_width) {

	int charcount = 0, spacecount = 0;
	char nextchar = 'a';

	while( nextchar != '\0' ) {

		nextchar = getNextChar( string++ );

		charcount++;

		if( nextchar == SPACE ) {

			++spacecount;

			placeTabIfTabstopReached( output_string , tabstop_width , &charcount , &spacecount );

		} else {

			placeSpacesBeforeTabstop( output_string , &spacecount );

			sendCharToOutputString( output_string , nextchar );

		}

	}

}

void placeTabIfTabstopReached(char * output_string, int tabstop_width, int * charcount, int * spacecount) {

	if( TABSTOP_REACHED( *charcount , tabstop_width ) ) {

		sendCharToOutputString( output_string , TAB );

		*charcount = *spacecount = 0;

	}

}

void placeSpacesBeforeTabstop(char * output_string, int * spacecount) {
			
	while( *spacecount ) {

		sendCharToOutputString( output_string , SPACE );

		--*spacecount;

	}

}