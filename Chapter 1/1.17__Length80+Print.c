#include "stdio.h"

#define MAXLENGTH 100
#define EOI '%'

int getLine(char buffer[])
{
	int length = 0;
	char c;
	
	while( ((c = getchar()) != EOI) && (c != '\n') && (length < MAXLENGTH) )
	{
		++length;

		if(length >= MAXLENGTH)
		{
			while( ((c = getchar()) != EOI) && (c != '\n') )
				++length;
		}
	}

	return length;
}

void main()
{
	int i = 1, length;
	char inputbuffer[MAXLENGTH];

	while( (length = getLine(inputbuffer)) > 0 )
	{
		if(length > 80)
			printf("Line %d : %d\n", i, length);
		i++;
	}
}	