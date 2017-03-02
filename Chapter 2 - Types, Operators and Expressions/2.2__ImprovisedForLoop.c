#include "stdio.h"
#include "Global_Parameters.h"

/* 
	Improvised For Loop for getLine Function in Chapter 1, 
	without using Logical Operators 
*/

int main()
{
	int i, lim = 10;
	char c;

	/* Original Version of for loop :-

		for( i = 0 ; i < lim -1 && (c = getchar()) != EOI && c != '\n' ; ++i ) ;

	*/

	// Without using Logical Operators (Version 1) :-

	for( i = 8; (i < lim -1) * ( (c = getchar()) != EOI ) * (c != '\n') ; ++i )

		printf("All conditions true, Loop executed succesfully !");

	/*
	Using Conditional Operator (Version 2) :-

	for( i = 8 ; i < lim - 1 ? ( (c = getchar()) != EOI ? ( (c != '\n') ? 1 : 0 ) : (0) ) : (0) ; ++i)

		printf("All conditions true, Loop executed succesfully !");
	*/

	return 0;
}