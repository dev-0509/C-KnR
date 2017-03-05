#include "stdio.h"
#include "string.h"
#include "Global.h"

void sendCharacterToOutputBuffer(char character)
{
	static int index = 0;

	switch( character )
	{
		case '\n' : strcat( gOutputBuffer , "\\n" );
					index += 2;
								
						break;

		case '\t' : strcat( gOutputBuffer , "\\t" );
					index += 2;

						break;

		default   : gOutputBuffer[index++] = character;
						break;
	}
}

void printOutputBuffer()
{
	printf("\n%s\n", gOutputBuffer);
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

void checkEscapeCharacter()
{
	int index = 0, character;

	while( gInputBuffer[index] != '\0' )
	{
		character = checkCharacter( gInputBuffer[index] );

		sendCharacterToOutputBuffer( character );

		++index;
	}
}

void readString()
{
	FILE *p;
	char c, index = 0;

	p = fopen( filename , READ );

	while( (c = fgetc(p)) != EOF )

		gInputBuffer[index++] = c;

	gInputBuffer[index] = '\0';
}

int main()
{
	readString();

	checkEscapeCharacter();

	printOutputBuffer();

	return 0;
}