#include "stdio.h"
#include "stdlib.h"
#include "readlines.h"

void openFile(FILE ** fptr) {

	char filename[] = "input_file.txt";

	*fptr = fopen( filename , READ );

}

void fetchMemoryForStorage(char ** string_ptr, int length) {

	*string_ptr = ( char * )malloc( length );

}

int checkOverflow(int no_of_lines) {

	if( no_of_lines >= MAXLINES )

		return OVERFLOW;

	return STORAGE_AVAILABLE;

}

void checkMemoryStatus(int status) {

	if( status != SUCCESS ) {

		printf("\nInput too large");

		exit( 0 );

	}

}