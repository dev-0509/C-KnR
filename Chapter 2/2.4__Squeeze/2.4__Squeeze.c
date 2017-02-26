#include "stdio.h"
#include "string.h"
#include "Global_Parameters.h"

char mainstring[MAXLENGTH], string[MAXLENGTH];
char charactersread[MAXLENGTH];
int positionsread[MAXLENGTH];
int squeezeposition[MAXLENGTH];

void readStrings()
{
	FILE *p;
	int index = 0;

	p = fopen("C:\\Users\\devsa\\Desktop\\Study !\\Programs\\C-KnR\\Chapter 2\\2.4_InputCase.txt","r");

	while( ! (feof(p)) )
	{
		while((c = fgetc(p)) != '\n')
			mainstring[index++] = c;

		mainstring[index] = '\0';

		index = 0;

		while((c = fgetc(p)) != EOF)
			string[index++] = c;

		string[index] = '\0';
	}
}

void squeeze(int position)
{
	char temp;

	mainstring[position] = ' ';

	while(mainstring[position] != '\0')
	{
		temp = mainstring[position];
		mainstring[position] = mainstring[position + 1];
		mainstring[position + 1] = temp;

		if(mainstring[position] == '\0')
			break;

		++position;
	}
}

void adjustSqueezePosition(int position)
{
	int temp;

	squeezeposition[position] = 0;

	while( position <= (strlen(mainstring)) )
	{
		temp = squeezeposition[position];
		squeezeposition[position] = squeezeposition[position + 1];
		squeezeposition[position + 1] = temp;

		++position;
	}
}

int isPositionRead(int position)
{
	static int index = 0;
	int i = 0;

	while(i < index)
	{
		if(positionsread[i] == position)
		{
			if(squeezeposition[position] == 0)
				return 1;
			else
				return 0;
		}
		else
			++i;
	}

	positionsread[index++] = position;

	return 0;	
}

void squeezeString()
{
	int i, index = 0, counter = 0;

	while(index < MAXLENGTH)
	{
		if(squeezeposition[index - counter] == 1)
		{
			if( isPositionRead(index - counter) )
				break;

			squeeze(index - counter);

			adjustSqueezePosition(index - counter);

			++counter;

			++index;
		}
		else
			++index;
	}
}

void setSqueezePosition(char character)
{
	int index = 0;

	while(mainstring[index] != '\0')
	{
		if(mainstring[index] == character)
			squeezeposition[index] = 1;
			
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
	int index = 0;

	readStrings();

	printf("%s\n%s", mainstring, string);

	while(string[index] != '\0')
	{
		if( ! (isCharacterAlreadyRead(string[index])) )

			setSqueezePosition(string[index]);

		++index;
	}

	squeezeString();

	printf("\n\n\tSqueezed String : %s\n", mainstring);

	return 0;
}