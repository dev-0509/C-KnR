#include "stdio.h"
#include "Global_Parameters.h"

#define TABSTOP 6

int main()
{
	int i = 0, spaces, charactersread = 0;

	while((c = getchar()) != EOI)
	{
		if(c == '\t')
		{
			if(charactersread < TABSTOP)
				spaces = TABSTOP - charactersread;
			else if(charactersread == TABSTOP)
				spaces = TABSTOP;
			else
				spaces = charactersread % TABSTOP;	

			while(i < spaces)
			{
				printf(" ");
				i++;
			}

			i = charactersread = 0;
		}
		else
		{
			if(c != '\n')
			{
				printf("%c", c);
				++charactersread;
			}
		}
	}

	return 0;
}