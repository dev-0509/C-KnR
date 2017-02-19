#include<stdio.h>
#include<conio.h>
void main()
{
	char c;
	c = (getchar() != EOF);

	if(c == 1 || c == 0)
	{
		if(c == 1)
			printf("getchar() != EOF returns 1");
		else
			printf("getchar() != EOF returns 0");
	}
	else
		printf("getchar() != EOF does not return 0 or 1");
}
