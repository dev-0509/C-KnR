#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "Global_Parameters.h"

int removeTrailingBlanks(char buffer[])
{
	int i = 0, flag = 0;

	while(buffer[i++] != '\0');

	i--;

	while(buffer[--i] == ' ')
	{
		if(i == 0)
		{
			buffer[i] = '\0';
			printf("Bad Input ! Blank Line Deleted\n\n");
			return 0;
		}
		flag = 1;
	}

	if(flag == 0)
		return flag;
	else
		buffer[++i] = '\0';

	return flag;
}

int main()
{
	char inputbuffer[MAXLENGTH], end, flag, length;

	do
	{
		printf("\n");

		while( getLine(inputbuffer) )
		{
			length = strlen(inputbuffer);

			flag = removeTrailingBlanks(inputbuffer);

			if(flag == 1)
			{
				printf("\tLength of input line : %d\n", length);
				printf("\tTrailing Blanks removed, Length : %d\n", strlen(inputbuffer));
				printf("%s\n\n", inputbuffer);
			}

			clearBuffer(inputbuffer);
		}

		printf("\tEnd of Input ? (y/n) : ");
		end = getche();

	}while(end != 'y');

	return 0;
}