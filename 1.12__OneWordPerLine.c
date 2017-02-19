#include <stdio.h>
#include <conio.h>

void main()
{
	char c;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n')
			printf("\n");
		else
			printf("%c", c);
	}
}