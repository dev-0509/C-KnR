#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100

void reverse(char * string , char * target_string) {

	static int index = -1, i = 0;

	++index;

	if( string[ index ] == '\0' ) 
		
		return;

	else {

		reverse( string , target_string );

	}

	target_string[ i++ ] = string[ --index ];

}

void getStringFromCmd (int argc , char const * argv[] , char string[]) {

	strcpy( string , argv[1] );

}

int main (int argc, char const * argv[]) {

	int index;
	char string[ MAXLENGTH ], target_string[ MAXLENGTH ];

	getStringFromCmd ( argc , argv , string );

	reverse ( string , target_string );

	target_string[ strlen( target_string ) ] = '\0';

	printf("%s", target_string);
	
	return 0;

}