#include "stdio.h"
#include "string.h"
#include "Global.h"

/*

=>	Program concatenates two strings and the first string is the new updated / concatenated
	string.

	Implements the concept of Pointer Arithmetic as pointers are used for string 
	manipulations performed, instead of arrays and array indexing.

*/

void displayResult(int status, char * string) {

	if( status )

		printf("%s", string);

	else

		printf("Concatenation Not Possible!");

}

int checkLengthOfConcat_string(char * source_string, char * concat_string) {

	int source_string_length;
	int concat_string_length;

	source_string_length = strlen( source_string );
	concat_string_length = strlen( concat_string );

	if( MAXLENGTH - source_string_length > concat_string_length )

		return CONCAT_POSSIBLE;

	else

		return CONCAT_NOT_POSSIBLE;

}

int str_cat(char * source_string, char * concat_string) {

	int status;

	status = checkLengthOfConcat_string( source_string , concat_string );

	if( status ) {

		source_string += strlen( source_string );

		while( ( *source_string++ = *concat_string++ ) != END_OF_STRING ) ;

		return SUCCESS;

	} else

		return CONCAT_NOT_POSSIBLE;

}

void fetchStringsFromCmd(char const * argv[], char * source_string, char * concat_string) {

	strcpy( source_string , argv[ 1 ] );

	strcpy( concat_string , argv[ 2 ] );

}

int main(int argc, char const * argv[]) {

	char source_string[ MAXLENGTH ], concat_string[ MAXLENGTH ];
	int status;

	fetchStringsFromCmd( argv , source_string , concat_string );

	status = str_cat( source_string , concat_string );

	displayResult( status , source_string );

	return 0;

}