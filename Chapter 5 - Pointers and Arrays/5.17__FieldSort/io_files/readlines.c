#include "stdio.h"
#include "string.h"
#include "../header_files/readlines.h"

void fetchInputLines(char * lines[], int * no_of_lines , int * memory_status) {

	*memory_status = populateBufferFromFile( lines , &no_of_lines );

	checkMemoryStatus( *memory_status );

}

int populateBufferFromFile(char * lines[], int ** line_no) {

	char * string_ptr, newline[ MAXLENGTH ];
	int length, no_of_lines;

	while( LINE_EXISTS( newline , length ) ) {

		fetchMemoryForStorage( &string_ptr , length );

		if( string_ptr == NULL )

			return STORAGE_NOT_AVAILABLE;

		else {

			storeLine( lines , &line_no , newline , string_ptr );

			checkOverflow( **line_no );

		}

	}

	return SUCCESS;

}

int getLine(char * line) {

	int index = 0;
	char nextchar;

	FILE * fptr;
	static int file_ptr_position = 0;

	openFile( &fptr );

	fseek( fptr , file_ptr_position , SEEK_SET );

	while( ( index < MAXLENGTH ) && NEW_CHARACTER_EXISTS( nextchar , fptr ) ) {

		if( feof( fptr ) )

			break;

		line[ index++ ] = nextchar;

	}

	line[ index ] = '\0';

	file_ptr_position = ftell( fptr );

	return index;

}

void storeLine(char * lines[], int *** line_no, char * newline, char * string_ptr) {

	strcpy( string_ptr , newline );

	lines[ ( ***line_no )++ ] = string_ptr;

}