#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "Global_Parameters.h"

#define MAX_LINE_LENGTH 50

int main()
{
	int length, i = 1, indexjump = 1, flag = 0;
	char end, line[MAXLENGTH];

	do
	{
		while( getLine(line) )
		{
			length = strlen(line);

			if(length == 0)
			{
				printf("\nBad Input ! Enter a line\n\n");
				continue;
			}

			while(length > MAX_LINE_LENGTH)
			{
				if(line[MAX_LINE_LENGTH * indexjump] == ' ')
					line[MAX_LINE_LENGTH * indexjump] = '\n';
				else
				{
					while(line[(MAX_LINE_LENGTH * indexjump) - i] != ' ')
					{
						if( ((MAX_LINE_LENGTH * indexjump) - i) == 0 )
						{
							flag = 1;
							break;
						}	

						++i;
					}

					if(flag != 1)
						line[(MAX_LINE_LENGTH * indexjump) - i] = '\n';
				}

				length = MAX_LINE_LENGTH - length;

				if(length > MAX_LINE_LENGTH)
					++indexjump;
			}
			i = flag = 0;
			indexjump = 1;

			displayLine(line);

			clearBuffer(line);
		}

		printf("\n\tEnd of Input ? (y/n) : ");
		end = getche();
		printf("\n\n");

	}while(end != 'y');

	return 0;
}