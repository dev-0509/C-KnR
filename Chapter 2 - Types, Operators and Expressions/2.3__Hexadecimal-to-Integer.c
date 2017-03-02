#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "Global_Parameters.h"

#define DIGIT(string) string>='0'&&string<='9'
#define UPPERCASE(string) string>='A'&&string<='F'
#define LOWERCASE(string) string>='a'&&string<='f'

int isStringHexadecimal(char string[])
{
	int index = 1, invalidstring = 0;

	if( ! (string[0] == '0' && ( string[1] == 'x' || string[1] == 'X')) )
		return 0;

	while(string[++index] != '\0')
	{
		if( DIGIT(string[index]) )
			continue;

		if( UPPERCASE(string[index]) )
			continue;

		if( LOWERCASE(string[index]) )
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

int power(int base, int power)
{
	int number = 1;

	while(power--)
		number *= base;

	return number;
}

long htoi(char hex_string[])
{
	int i, index = 1, digit, pow;
	long int integervalue = 0;

	pow = ( strlen(hex_string) ) - 3 ;

	while(hex_string[++index] != '\0')
	{
		if( DIGIT(hex_string[index]) )
			digit = hex_string[index] - '0';

		else if( UPPERCASE(hex_string[index]) )
			digit = hex_string[index] - '8';

		else 
			digit = hex_string[index] - 'W';

		integervalue += digit * power(16 , pow);

		--pow;
	}

	return integervalue;
}

int main()
{
	char string[MAXLENGTH], a;
	long int integervalue = 0; 

	printf("\nEnter the Hexadecimal String : ");
	gets(string);

	if( isStringHexadecimal(string) )
	{
		integervalue = htoi(string);

		printf("\nInteger equivalent of %s : %d\n", string, integervalue);
	}
	else
		printf("\nEnter a Valid Hexadecimal String !");

	return 0;
}