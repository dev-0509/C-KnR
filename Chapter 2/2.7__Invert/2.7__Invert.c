#include "stdio.h"
#include "Global_Parameters.h"

int invert()
{
	int shift;

	shift = ( -1 << ( position + no_of_bits - 1) );

	number = number ^ shift;

	return number;
}

int main()
{
	getInput();

	number = invert();

	printf("\n! Two's Complement of the final answer ! \n\n%d\n", number);

	return 0;
}