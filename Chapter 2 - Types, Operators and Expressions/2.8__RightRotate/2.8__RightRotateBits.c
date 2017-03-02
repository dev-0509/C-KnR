#include "stdio.h"
#include "Global.h"

int calculateBitsLeftAfterTruncate(int bits)
{
	int bitcount = 0;

	while(bits != 0)
	{
		bits = bits >> 1;

		++bitcount;
	}

	return bitcount;
}

int rightRotate()
{
	rotated_number = number & ~( ~0 << no_of_bits );

	bits_left = number >> no_of_bits;

	count = calculateBitsLeftAfterTruncate(bits_left);

	rotated_number = rotated_number << count;

	rotated_number = rotated_number | bits_left;

	return rotated_number;
}

int main()
{
	getInput();
	
	rotated_number = rightRotate(number , no_of_bits);

	printf("\nRight Rotation of %d by %d Bits : %d\n", number, no_of_bits, rotated_number);

	return 0;
}