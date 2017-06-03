#include "stdio.h"
#include "string.h"
#include "Global.h"

void displayResult(int status) {

	if( status )

		printf("Substring present in the last!");

	else

		printf("Substring not present!");

}

int charactersEqual(char * string, char * substring) {

	if( *string == *substring )

		return EQUAL;

	else

		return NOT_EQUAL;

}

int str_end(char * string, char * substring) {

	int count = 0, substring_length;
	char substring_firstchar;

	substring_firstchar = *substring;
	substring_length = strlen( substring );

	string += strlen( string );
	substring += strlen( substring );

	while( *substring != substring_firstchar ) {

		if( charactersEqual( string , substring ) ) {

			count++;

			string--;	substring--;
			
		}

		else

			break;

	}

	if( count == substring_length )

		return PRESENT;

	else

		return NOT_PRESENT;

}

void fetchStringsFromCmd(char const * argv[], char * string, char * substring) {

	strcpy( string , argv[ 1 ] );

	strcpy( substring , argv[ 2 ] );

}

int main(int argc, char const *argv[]) {

	char string[ MAXLENGTH ], substring[ MAXLENGTH ];
	int status;

	fetchStringsFromCmd( argv , string , substring );

	status = str_end( string , substring );

	displayResult( status );

	return 0;

}