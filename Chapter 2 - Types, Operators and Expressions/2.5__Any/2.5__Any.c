#include "stdio.h"
#include "string.h"
#include "Global_Parameters.h"

void readStrings()
{
	FILE *p;
	int index;

	p = fopen("C:\\Users\\devsa\\Desktop\\Study !\\Programs\\C-KnR\\Chapter 2\\2.5__Any\\2.5_InputCase.txt","r");

	if(!p)
	{
		printf("\n\tFile Not Found !");
		return;
	}

	while( ! (feof(p)) )
	{
		index = readMainString(p);		

		mainstring[index] = '\0';

		index = readProcessorString(p);

		string[index] = '\0';
	}
}

int displayOccurences()
{
	int index = 0;

	while(string[index] != '\0')
	{
		if( isAlreadyDisplayed(index , string[index]) )
		{
			++index;
			continue;
		}

		display(string[index]);

		++index;
	}
	
	if( errorcounter == 0 )
		return FOUND;
	else
		return NOTFOUND;
}

void setFirstOccurence(char character)
{
	int index = 0;

	if(character == ' ')
		return;

	while(mainstring[index] != '\0')
	{
		if(mainstring[index] == character)
		{
			occurence[index] = 1;
			break;
		}
			
		++index;
	}
}

int isCharacterAlreadyRead(char character_read)
{
	static int index = 0;
	int i = 0;

	while(i < index)
	{
		if(charactersread[i] == character_read)
			return 1;
		else
			++i;
	}

	charactersread[index++] = character_read;

	return 0;
}

int main()
{
	int index = 0, no_occurences;

	readStrings();

	printf("%s\n%s\n\n", mainstring, string);

	while(string[index] != '\0')
	{
		if( ! (isCharacterAlreadyRead(string[index])) )
			
			setFirstOccurence(string[index]);

		++index;
	}

	no_occurences = displayOccurences();

	if( no_occurences )
		printf("%d\n", no_occurences);

	return 0;
}