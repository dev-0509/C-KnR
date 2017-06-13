#include "stdio.h"
#include "entab.h"

void entab(char * string, char * output_string, int tabstop_width, int start_column) {

	int charcount, column_no;
	char nextchar = 'a';

	charcount = column_no = 0;

	while( nextchar != END_OF_STRING ) {

		nextchar = getNextChar( string++ );

		++column_no;	++charcount;

		if( column_no >= start_column )

			performEntab( nextchar , output_string , tabstop_width , &charcount );

		else

			sendCharToOutputString( output_string , nextchar );

	}

}

void performEntab(char nextchar, char * output_string, int tabstop_width, int * charcount) {

	static int spacecount = 0;

	if( nextchar == SPACE ) {

		++spacecount;

		placeTabIfTabstopReached( output_string , tabstop_width , &charcount , &spacecount );

	} else {

		placeSpacesBeforeTabstop( output_string , &spacecount );

		sendCharToOutputString( output_string , nextchar );

	}

}

void placeTabIfTabstopReached(char * output_string, int tabstop_width, int ** charcount, int * spacecount) {

	if( TABSTOP_REACHED( **charcount , tabstop_width ) ) {

		sendCharToOutputString( output_string , TAB );

		**charcount = *spacecount = 0;

	}

}

void placeSpacesBeforeTabstop(char * output_string, int * spacecount) {
			
	while( *spacecount ) {

		sendCharToOutputString( output_string , SPACE );

		--*spacecount;

	}

}