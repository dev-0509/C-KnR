#include "stdio.h"
#include "Global.h"

int main()
{
	char character;

	character = get_ch();

	printf("\n\tInput : %c ", character);

	unget_ch( 'd' );

	character = get_ch();

	printf("\n\tPushed Character : %c\n\n", character);

	return 0;
}

char promptUserForInput()
{
	printf("\n\tEnter the character : ");

	return ( getchar() );
}

char pushed_character = EMPTY;

char get_ch()
{
	char ch;

	if( pushed_character == EMPTY )

		return ( promptUserForInput() );

	else
	{
		ch = pushed_character;

		pushed_character = EMPTY;

		return ch;
	}
}

void unget_ch(char character)
{
	pushed_character = character;
}