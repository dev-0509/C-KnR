#include "stdio.h"
#include "Global_Parameters.h"

int invert()
{
	bit_disabler = ( -1 << (position + 1) );

	replacer = ( 2 << position );

	bits_number = number & ~( ~0 << (position + 1 - no_of_bits) );

	bits_inverted = ~ ( number >> (position + 1 - no_of_bits) & ~( ~0 << (no_of_bits) ) );

	/*bits_inverted = bits_inverted << ( (position + 1 - no_of_bits) );

	number = number & bit_disabler;

	replacer = replacer | bits_number;

	replacer = replacer | bits_inverted;

	replacer = replacer ^ ( 1 << (position + 1) );

	number = number | replacer;*/

	printf("%d", bits_inverted	);
}

int main()
{
	getInput();

	invert();

	return 0;
}