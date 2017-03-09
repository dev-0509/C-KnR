#include "stdio.h"
#include "string.h"
#include "Global.h"

/*
	~ Expand expressions like "a-z" or "0-9" into corresposding ranges, ie, 'a' to 'z' or 
	  '0' to '9'

	~ Expand expressions like "-a-z" or "a-z-" into corresponding ranges, ie, '-a' to 'z'
	  or 'a-' to 'z-'
*/

void printOutputBuffer()
{
	printf("%s\n\n", outputbuffer);
}

void putCharToOutputBuffer(char character)
{
	outputbuffer[out_buf_index++] = character;
}

void checkForRotation()
{
	if( (start_char == 'z' || start_char == 'Z') && 
					(start_char != end_char) 		)
	{
		if( start_char == 'z' )
			start_char = 'a';

		else
			start_char = 'A';
	}
}

void expand(char character)
{
	putCharToOutputBuffer( character );

	checkForRotation( character , end_char );
}

void setRange()
{
	while( buffer[i++] != '-' );

	start_char = buffer[i - 2];
	end_char = buffer[i];
}

void expandWithoutSpecialCharacter()
{
	setRange();

	while(start_char != end_char)
	{
		expand( start_char );

		++start_char;
	}

	putCharToOutputBuffer( end_char );
}

void expandWithSpecialCharacter()
{
	setRange();

	while( start_char != end_char )
	{
		if( leading_special_char == TRUE )
		{
			putCharToOutputBuffer( special_char );

			expand( start_char );
		}

		else
		{
			expand( start_char );

			putCharToOutputBuffer( special_char );
		}

		++start_char;
	}

	if(leading_special_char == TRUE)
	{
		putCharToOutputBuffer( special_char );
		putCharToOutputBuffer( end_char );
	}
	else
	{
		putCharToOutputBuffer( end_char );
		putCharToOutputBuffer( special_char );
	}
}

void setSpecialCharacterOccurence()
{
	if( buffer[0] == special_char )
	{
		leading_special_char = TRUE;
		++i;
	}

	else
		leading_special_char = FALSE;
}

int isSpecialCharacter()
{
	int counter = 0;

	if( ! ( NOT_NUMBER(buffer[0]) ) )
		return FALSE;

	if( ! (NOT_NUMBER(buffer[(strlen(buffer) - 1)]) ) )
		return FALSE;

	if( NOT_UPPERCASE( buffer[0] ) && NOT_LOWERCASE( buffer[0] ) ) 
		return TRUE;	

	if( NOT_UPPERCASE(buffer[(strlen(buffer) - 1)]) && 
		NOT_LOWERCASE(buffer[(strlen(buffer) - 1)])    ) 
		return TRUE;

	return FALSE;
}

char getSpecialCharacterIfAny()
{
	if( isSpecialCharacter() )
	{	
		if( (NOT_UPPERCASE( buffer[0] ) && NOT_LOWERCASE( buffer[0] )) )
			
			return buffer[0];

		else
		
			return buffer[ (strlen(buffer) - 1) ];
	}

	return NOTFOUND;
}

void expandString()
{
	special_char = getSpecialCharacterIfAny();

	if( special_char != 0 )
	{
		setSpecialCharacterOccurence();

		while( buffer[i] != '\0' )
		{
			expandWithSpecialCharacter();
			
			if( buffer[i + 1] == '\0' )
				break;
			else if( buffer[i + 2] == '\0')
				break;
		
			++i;			
		}
	}

	else
	{
		while( buffer[i] != '\0' )
		{
			expandWithoutSpecialCharacter();			

			if( buffer[i + 1] == '\0' )
				break;

			++i;
		}
	}
}

void getStringIntoBuffer(FILE *fptr)
{
	int index = 0;
	char c;

	while(( c = fgetc(fptr) ) != '\n')
	{
		if(c == EOF)
			break;

		buffer[index++] = c;
	}

	buffer[index] = '\0';
}

int main()
{
	FILE *fileptr;
	
	fileptr = fopen( filename , READ );

	while( ! ( feof(fileptr) ) )
	{
		getStringIntoBuffer( fileptr );

		expandString();

		printOutputBuffer();

		clearBuffers();
	}

	return 0;
}