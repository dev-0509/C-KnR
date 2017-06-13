#include "stdio.h"
#include "entab.h"

/*

Please browse the 'entab_explanation' text file for a gist of this program!

=>	Improvisation:	Accepts shorthand notations from the terminal denoting the Tab Width
				and the column number after which Tabstops would activate.

			Eg:	entab_executable.out +tabwidth <value> -column <value>

			Where, -column: Column number after which Tabstops starts

*/

int main(int argc, char const *argv[]) {

	char string[ MAXLENGTH ], output_string[ MAXLENGTH ];

	int tabstop_width, start_column;

	readInputFromFile( string );

	if( argc > 1 )

		fetchTabSpecifications( argv , &tabstop_width , &start_column );

	entab( string , output_string , tabstop_width , start_column );

	displayOutputString( output_string );

	return 0;

}