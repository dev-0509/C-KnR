#include "stdio.h"
#include "string.h"
#include "Global.h"
#include "StringHandler.h"

int checkLengthOfConcatString(char * main_string, int no_of_chars) {

	if( MAXLENGTH - strlen( main_string ) < no_of_chars )

		return OVERFLOW;

	return POSSIBLE;

}

int concatStrings(char * main_string, char * concat_string, int no_of_chars) {

	int status, char_count = 0;

	status = checkLengthOfConcatString( main_string , no_of_chars );

	if( status == OVERFLOW )

		return CONCAT_NOT_POSSIBLE;

	main_string += strlen( main_string );

	while( char_count < no_of_chars ) {

		*main_string++ = *concat_string++;

		++char_count;

	}

	*main_string = '\0';

	return SUCCESS;

}