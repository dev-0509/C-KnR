#include "stdio.h"
#include "stdlib.h"
#include "Global_Parameters.h"

/*
   Replaces 'n' Bits from a particular position in a number by the 'n' rightmost Bits 
   of another number
*/

int setBits()
{
	bit_disabler = ( -1 << (position + 1) );

	replacer = ( 2 << position );

	bits_number = number & ~( ~0 << (position + 1 - no_of_bits) );

	bits_replacewith = replacewith & ~( ~0 << no_of_bits );

	bits_replacewith = bits_replacewith << ( (position + 1 - no_of_bits) );

	number = number & bit_disabler;

	replacer = replacer | bits_number;

	replacer = replacer | bits_replacewith;

	replacer = replacer ^ ( 1 << (position + 1) );

	number = number | replacer;

	return number;
}

int main()
{
	getInput();

	number = setBits();

	printf("\n%d\n", number);

	return 0;
}