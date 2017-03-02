#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "Global_Parameters.h"

char * reverse(char buffer[], char line[])
{
	char i = 0, j = 0, lastindex;

	while(buffer[i++] != '\0'); 

	--i;

	while(i != 0)
		line[j++] = buffer[--i];

	line[j] = '\0';

	return line;
}

int main()
{
	char i = 0, character = 0, inputbuffer[MAXLENGTH], length, end, reversedline[MAXLENGTH];

	do
	{
		printf("\n");

		while( getLine(inputbuffer) )
		{
			length = strlen(inputbuffer);

			while(inputbuffer[i] != '\0')
			{
				if(inputbuffer[i++] == ' ')
					++character;
			}

			if(character != length)
			{
				reverse(inputbuffer, reversedline);

				printf("%s\n\n", reversedline);
			}
			else
				printf("Bad Input ! Enter a Line\n\n");

			clearBuffer(inputbuffer);

			i = character = 0;
		}

		printf("\tEnd of Input ? (y/n) : ");
		end = getche();

	}while(end != 'y');

	return 0;
}