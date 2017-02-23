#include "stdio.h"
#include "limits.h"

int main()
{
	printf("\n\t\tCOMPILER : GCC");

	printf("\n\nCHARACTER -");
	printf("\n\tSigned Range : %d to %d", CHAR_MIN, CHAR_MAX);
	printf("\n\t\tMinimum Value of Unsigned Char : %d", (2 * CHAR_MIN) + (UCHAR_MAX + 1));
	printf("\n\t\tMaximum Value of Unsigned Char : %d", UCHAR_MAX);

	printf("\n\nINTEGER -");
	printf("\n\tSigned Range : %d to %d", INT_MIN, INT_MAX);
	printf("\n\t\tMinimum Value of Unsigned Int : 0");
	printf("\n\t\tMaximum Value of Unsigned Int : %u", UINT_MAX);

	printf("\n\nSHORT -");
	printf("\n\tSigned Range : %d to %d", SHRT_MIN, SHRT_MAX);
	printf("\n\t\tMinimum Value of Unsigned Short : 0");
	printf("\n\t\tMaximum Value of Unsigned Short : %u", USHRT_MAX);

	printf("\n\nLONG -");
	printf("\n\tSigned Range : %d to %d", LONG_MIN, LONG_MAX);
	printf("\n\t\tMinimum Value of Unsigned Long : 0");
	printf("\n\t\tMaximum Value of Unsigned Long : %lu\n", ULONG_MAX);	

	return 0;
}