#include "stdio.h"
#include "stdlib.h"
#include "readlines.h"


//---------------------------------------------------------- INPUT ---------------------------------------------------------//

int fetchNoOfLinesFromUser(int * last_n_lines  , int no_of_lines) {

	system( "clear" );

	printf("\nMaximum Lines: %d\n\nNumber of Lines to be printed: ", no_of_lines);

	scanf( "%d" , last_n_lines );

	if( *last_n_lines > no_of_lines ) {

		printf("\nInvalid Input!\n\n");

		return INVALID_INPUT;

	}

	else

		return VALID_INPUT;

}

//--------------------------------------------------------------------------------------------------------------------------//


//---------------------------------------------------------- OUTPUT ---------------------------------------------------------//

void printLastNLines(char * lines[], int last_n_lines, int no_of_lines) {

	int line_no;

	system( "clear" );

	line_no = ( no_of_lines - last_n_lines );

	while( line_no < no_of_lines ) {

		printLineIndex( line_no );

		printf("%s\n", lines[ line_no ]);

		++line_no;

	}

	printf("\n");

}

void printLineIndex(int line_no) {

	if( ( line_no + 1 ) < 10 )

		printf(" %d. ", ( line_no + 1 ) );

	else

		printf("%d. ", ( line_no + 1 ) );

}

//--------------------------------------------------------------------------------------------------------------------------//