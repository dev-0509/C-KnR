#include "stdio.h"
#include "string.h"
#include "Global.h"
#include "StringHandler.h"

int isCopiedStringGreater(char * main_string, int no_of_chars) {

	if( no_of_chars > strlen( main_string ) )

		return GREATER;

	return NOT_GREATER;
}

int copyStrings(char * main_string, char * copied_string, int no_of_chars) {

	int char_count = 0;

	while( char_count < no_of_chars ) {

		++char_count;

		*main_string++ = *copied_string++;

	}

	if( isCopiedStringGreater( main_string , no_of_chars ) )

		*main_string = '\0';

	return SUCCESS;

}