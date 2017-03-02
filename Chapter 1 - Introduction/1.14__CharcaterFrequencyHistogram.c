#include "stdio.h"
#include "Global_Parameters.h"

int characterarray[26];

void main()
{
	int i = 0, count;

	while((c = getchar()) != EOI)
	{
		if(c >= 97 && c <= 122)
			++characterarray[c - 97];
		else if(c >= 65 && c <= 90)
			++characterarray[c - 65];
	}

	printf("\nFREQUENCY HISTOGRAM :-\n\t\t");

	while(i < 26)
	{
		if(characterarray[i] == 0)
		{
			i++;
			continue;
		}
		else
		{
			count = characterarray[i];

			printf("\n\t\t%c %c", (i + 97), 186);

			while(characterarray[i])
			{
				printf("%c", 254);
				characterarray[i]--;
			}
			printf(" (%d)", count);
		}
		
		i++;
	}
}