#include <stdio.h>

#define swap( type , arg1 , arg2 ) { \
									type temp; \
									temp = arg1; \
									arg1 = arg2; \
									arg2 = temp; \
								}

int main( void ) {

	int num1, num2;

	printf("\n\tEnter the numbers to swap: ");
	scanf("%d %d", &num1, &num2);

	swap( int , num1 , num2 );

	printf("Swapped Values => Number 1: %d \t Number 2: %d\n", num1 , num2 );
		
	return 0;
}