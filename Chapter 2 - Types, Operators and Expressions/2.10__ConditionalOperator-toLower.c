#include "stdio.h"
#include "Global_Parameters.h"

char toLower(char character)
{
	character = (character >=65 && character <= 90) ? ( character + 32 ) : character;

	return character;	
}

int main()
{
	char character;

	while((character = getchar()) != EOI)
	{
		character = toLower(character);	

		printf("%c", character);
	}
	
	return 0;
}