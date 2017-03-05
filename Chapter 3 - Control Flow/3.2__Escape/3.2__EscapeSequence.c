#include "stdio.h"
#include "string.h"
#include "Global.h"

// Print Newlines and Tabs in a string, explicitely as Escaped Characters

void sendCharacterToOutputBuffer(char character)
{
	static int index = 0;

	switch( character )
	{
		case NEWLINE : strcat( gOutputBuffer , "\\n" );
					   		index += 2;
					             
					   break;

		case TAB 	 : strcat( gOutputBuffer , "\\t" );
					   		index += 2;

				  	   break;

		default   	 : gOutputBuffer[index++] = character;
							      
					   break;
	}
}

char checkCharacter(char character)
{
	switch( character )
	{
		case '\n' : return NEWLINE;

		case '\t' : return TAB;

		default	  : return character;
	}
}

char getNextCharacter()
{
	static int index = 0;

	if( gInputBuffer[index] == '\0')
		return END_OF_STRING;

	else
		return gInputBuffer[index++];
}

void checkEscapeCharacter()
{
	char newcharacter;

	while( newcharacter = getNextCharacter() )
	{
		newcharacter = checkCharacter( newcharacter );

		sendCharacterToOutputBuffer( newcharacter );
	}
}

void populateStringInBuffer()
{
	FILE *p;
	char c, index = 0;

	p = fopen( filename , READ );

	while( (c = fgetc(p)) != EOF )

		gInputBuffer[index++] = c;

	gInputBuffer[index] = '\0';
}

void printOutputBuffer()
{
	printf("\n%s\n", gOutputBuffer);
}

int main()
{
	populateStringInBuffer();

	checkEscapeCharacter();

	printOutputBuffer();

	return 0;
}