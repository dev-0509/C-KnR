#include "stdio.h"
#include "Global_Parameters.h"

void main()
{
	int wordlength = 0;

	while((c = getchar()) != EOI)
	{
		if( c == ' ' || c == '\n' || c == '\t') 
		{
			if(wordlength != 0)
			{
				printf("\n\t\t%d %c", wordlength, 186);

				while(wordlength)
				{
					printf("%c", 254);	
					wordlength--;
				}
			}
		}
		else
			++wordlength;
	}
}