#include "stdio.h"
#include "detab.h"

    /*
	Please browse the 'detab_explanation' text file for a gist of this program!

	Improvisation:	Accepts Tab Width as a terminal arguement and thereby operates
			over it.
				 */

int main(int argc, char const *argv[]) {

	char string[ MAXLENGTH ], output_string[ MAXLENGTH ];

	int tabstop_width;

	readInputFromFile( string );

	if( argc > 1 )

		fetchTabstopWidth( argv , &tabstop_width );

	else

		tabstop_width = TABSTOP;	/* Set TAB width with default width if no cmd arg. is encountered */

	detab( string , output_string , tabstop_width );

	displayOutputString( output_string );

	return 0;

}