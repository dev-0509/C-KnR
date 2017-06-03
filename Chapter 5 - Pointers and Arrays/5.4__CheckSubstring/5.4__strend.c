#include "stdio.h"
#include "string.h"
#include "Global.h"

/*

=> 	Program to verify if a particular string is a substring of another string, while searching
	the latter string, backwards.

	Eg: Suppose,
				
	CASE #1 | String 1: " hellohi "
		  String 2: " hi "

		  Now, string 2 is a substring of string 1 when we trace string 1 backwards, i.e,
		  in reverse direction.

	CASE #2 | String 1: " dev "
		  String 2: " saini "

		  Here, string 2 is not a substring of string 1 anywhere in string 1.

Happy Coding! :)

*/

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