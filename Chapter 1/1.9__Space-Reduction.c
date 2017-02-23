#include <stdio.h>
#include <conio.h>

int readInput(FILE *p, char *temparr)
{
	int i = 0;
	char c;

	while((c = fgetc(p)) != '\n')
	{
		*(temparr + i) = c;
		i++;
	}

	return i;
}

void clearArrays(char *inputarr, char *outputarr)
{
	int i = 100;

	for(;i--;)
		*(inputarr + i) = *(outputarr + i) = ' ';
}

void main()
{
	FILE *p;
	int index, j = 0, spacecount = 0;
	char c, a = 0, inputarr[100], outputarr[100];

	p = fopen("C:\\TurboC4\\TC\\BIN\\tst.txt","r");

	while( !(feof(p)) )
	{
		index = readInput(p, inputarr);

		while(inputarr[index] != '\n')
		{
			if(inputarr[index] == ' ')
			{
				while(inputarr[index++] == ' ')
					spacecount++;

				if(spacecount > 1)
				{
					while(inputarr[index] != ' ')
					{
						outputarr[j++] = inputarr[index++];
					}
					j++;
				}

				spacecount = 0;
			}
			if(index == 0)
			{
				while(inputarr[index] != ' ')
					outputarr[j++] = inputarr[index++];	

				j++;
			}
		}
		index = j = 0;

		clearArrays(inputarr, outputarr);
	}
}
