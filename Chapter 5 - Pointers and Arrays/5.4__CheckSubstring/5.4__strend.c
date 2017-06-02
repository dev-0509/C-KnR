#include "stdio.h"
#include "string.h"

int str_end(char * string, char * substring) {

	string += strlen( string );
	substring += strlen( substring );

	

}

void fetchStringsFromCmd(char const * argv[], char * string, char * substring) {

	strcpy( string , argv[ 1 ] );

	strcpy( substring , argv[ 2 ] );

}

int main(int argc, char const *argv[]) {

	char string[ MAXLENGTH ], substring[ MAXLENGTH ];

	fetchStringsFromCmd( argv , string , substring );

	str_end( string , substring );

	return 0;

}