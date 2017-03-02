// MACROS

#define MAXLENGTH 	300
#define NOTFOUND 	-1
#define FOUND 		0

// VARIABLES

char c;

char mainstring[MAXLENGTH], string[MAXLENGTH], charactersread[MAXLENGTH];
char occurence[MAXLENGTH];

int errorcounter = 1;
// FUNCTIONS

int readMainString(FILE *fptr)
{
	int index = 0;
	char ch;

	while((ch = fgetc(fptr)) != '\n')
		mainstring[index++] = ch;

	return index;
}

int readProcessorString(FILE *fptr)
{
	int index = 0;
	char ch;

	while((ch = fgetc(fptr)) != EOF)
		string[index++] = ch;

	return index;
}

int isAlreadyDisplayed(int index, char character)
{
	int i = 0;

	while(i < index)
	{
		if(character == string[i])
			return 1;

		++i;
	}	

	return 0;
}

void display(char character)
{
	int index = 0;

	while(index < (strlen(mainstring)) )
	{
		if(occurence[index] == 1)
		{
			if( character == mainstring[index] )
			{
				printf("\tFirst Occurence of %c : %d\n", character, index);

				errorcounter = 0;
			}
		}

		++index;
	}
}

