#include "stdio.h"
#include "string.h"
#include "Global.h"

/*	
	Code returns the Righmost Index in a String from where onwards, a pattern succesfully 
	matches the pattern in String

	If no occurence is found, returns (-1)
*/

int strrindex(char * string, char * pattern)
{
	int str_index = strlen( string ) - 1;
	int patt_index;

	while( string[str_index] != '\0' )
	{
		for( patt_index = strlen( pattern ) - 1 ; 

				string[str_index] == pattern[patt_index] ; 

								--str_index , --patt_index 	);

		if( patt_index < 0 )
			return ( str_index + 1 );
		
		else
			--str_index;
	}

	return NOT_FOUND;
}

void readInput(char * string, char * pattern)
{
	FILE *fptr;
	char c;

	fptr = fopen( filename , READ );

	while( (c = fgetc(fptr)) != '\n' )
		*string++ = c;

	*string = '\0';

	while( (c = fgetc(fptr)) != EOF )
		*pattern++ = c;

	*pattern = '\0';
}

int main()
{
	char string[MAXLENGTH];
	char pattern[MAXLENGTH];
	int position;

	readInput( string , pattern );
	
	position = strrindex( string , pattern );

	if( position != NOT_FOUND )
		printf("\nPosition of Righmost Occurence of Pattern in String : %d\n", position);
	
	else
		printf("\n%d : No occurence of Pattern in String", position);

	return 0;
}