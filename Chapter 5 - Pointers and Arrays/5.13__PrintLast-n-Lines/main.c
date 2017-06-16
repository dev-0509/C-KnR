#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*

=>	Program to display the last 'n' lines from an input source, value of 'n', 
	dynamically handled by the user.

	The code makes efficient use memory by utilising only the required number of Bytes
	to store the string in the system memory and not storing any lines if the memory
	limits are reached.


Happy Coding!
*/

int main(int argc, char const * argv[]) {

	char * lines[ MAXLINES ];

	int no_of_lines = 0, last_n_lines, memory_status, status;

	memory_status = populateBufferFromFile( lines , &no_of_lines );

	checkMemoryStatus( memory_status );

	status = fetchNoOfLinesFromUser( &last_n_lines  , no_of_lines );

	if( status == VALID_INPUT ) {

		printf("\nLast %d Lines =>\n", last_n_lines);

		printLastNLines( lines , last_n_lines , no_of_lines );	

	}

	return 0;

}