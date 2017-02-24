#include "stdio.h"
#include "stdlib.h"
#include "Global_Parameters.h"

int isStringHexadecimal(char string[])
{
	int index = 1, invalidstring = 0;

	if( ! (string[0] == '0' && ( string[1] == 'x' || string[1] == 'X')) )
		return 0;

	while(string[++index] != '\0')
	{
		if(string[index] >= '0' && string[index] <= '9')
			continue;

		if(string[index] >= 'a' && string[index] <= 'f')
			continue;

		if(string[index] >= 'A' && string[index] <= 'F')
			continue;

		invalidstring = 1;

		if(invalidstring == 1)
			break;
	}

	if(invalidstring == 1)
		return 0;
	else
		return 1;
}

/*int htoi(char hex_string[])
{

}*/

int main()
{
	char string[MAXLENGTH];

	printf("\nEnter the Hexadecimal String : ");
	gets(string);

	if( isStringHexadecimal(string) );
	//	htoi(string);

	return 0;
}