#include "stdio.h"
#include "stdlib.h"
#include "Global_Parameters.h"

void setBits()
{
	int requiredbits, replacerbits, final, truncate, result;

	requiredbits = number >> (position + 1 - no_of_bits);

	replacerbits = replacewith & ~( ~0 << no_of_bits );

	replacerbits = replacerbits << (position + 1 - no_of_bits);

	result =  number & ~( ~0 << (position - no_of_bits + 1) );

	result = ~( ~0 << (position + 1) ) & result;

	result = result | replacerbits;

	printf("%d", result);
}

int main()
{
	getInput();

	setBits();

	return 0;
}