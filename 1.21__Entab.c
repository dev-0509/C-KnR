/* The program replaces the number of spaces to '\t' by searching for the nearest TABSTOP
   If number of spaces terminate before a TABSTOP, then there was no tab, otherwise there
   is a Tab.
*/

#include "stdio.h"
#include "Global_Parameters.h"

#define TABSTOP 6

int main()
{
	int i, column = 0, tabs = 0, spaces = 0;

	while((c = getchar()) != EOI)
	{
		++column;

		if(c == ' ')
		{
			++spaces;

			if(spaces > 1)
			{
				if( (column % TABSTOP) == 0 )
				{
					++tabs;
					spaces = 0;
				}
			}
		}
		else
		{
			for(i = 0; i < tabs; i++)
				printf("\\t");

			if(spaces == 1)
				printf(" ");
			else if(spaces > 1)
			{
				for(i = 0; i < spaces; i++)
					printf(" ");
			}

			printf("%c", c);

			spaces = tabs = 0;
		}
	}

	return 0;
}