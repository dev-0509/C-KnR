#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "Global.h"

/*
	Polish Calculator : evaluates expressions by converting them into POSTFIX notations and 
						uses a Stack for arithmetic linking.

	Added Stack Manipulations to print the top of stack wihtout a pop, clear the entire Stack 
	and swap the penultimate and top elements of the stack


PS: --Beta Version-- Deals with single-digit Operands only :p
*/

int main(int argc, char const * argv[])
{
	int status;
	char choice;

	populateBufferFromCmd( argc , argv );

	status = polishCalculator();

	displayResult( status );

	printf("\n\nStack Manipulations ? (y/n) : ");
	scanf("%c", &choice);

	if( choice == 'y' )
		
		stackHandler();

	return 0;
}

char polishCalculator()
{
	int result, divisor, operand;
	char nextchar, string[ MAXSIZE ];

	while( ( nextchar = getOp( string ) ) != '\0' )
	{
		switch( nextchar )
		{
			case NUMBER : push( atoi(string) );
						  break;

			case '+' : result = pop() + pop();
					   push( result );
					   break;

			case '-' : operand = pop();
					   result = pop() - operand;
					   push( result );
					   break;

			case 'x' : result = pop() * pop();
					   push( result );
					   break;

			/* '~' Operator signifies division */
			case '~' : if( ( divisor = pop() ) == 0)
					   	return ERROR;

					   result = pop() / divisor;
					   push( result );
					   break;

			case '%' : if( ( divisor = pop() ) == 0)
					   	return ERROR;

					   result = pop() % divisor;
					   push( result );
					   break;		

			default : return ERROR;	
		}
	}

	return SUCCESS;
}

char getOp(char * string)
{
	char c;

	while( (string[0] = c = get_ch()) == ' ' || c == '\t' ) ;

	*(++string) = '\0';

	if( isdigit(c) )
		
		while( isdigit( c = get_ch() ) )
			*(++string) = c;

	else
		return c;

	*(++string) = '\0';

	if( c != '\0' )
		unget_ch( c );

	return NUMBER;
}

char buffer[ BUFFSIZE ];
int buffindex;

void populateBufferFromCmd(int argc, char const * argv[])
{
	int i = 1, index = 0;

	while ( i < argc )
	{
		buffer[ index++ ] = *argv[ i++ ];

		buffer[ index++ ] = ' ';
	}

	buffer[ index ] = '\0';
}

char get_ch( void )
{
	if( buffindex >= 0 )

		return buffer[ buffindex++ ];
}

void unget_ch(char c)
{
	if( buffindex < BUFFSIZE )

		buffindex--;
}

int stack[ BUFFSIZE ];
int topofstack;

void stackHandler()
{
	int choice;

	printf("\n\t1. Clear Stack");
	printf("\n\t2. Print Top of Stack");
	printf("\n\t3. Swap elements");

	printf("\n\nEnter your choice : ");
	scanf("%d", &choice);

	switch( choice )
	{
		case 1 : clearStack();
				break;
		case 2 : printTopOfStack();
				break;
		case 3 : swapPenultimateAndTopElements();
				break;

		default : printf("\nInvalid Choice !\n");
				break;
	}
}

void push(int value)
{
	++topofstack;

	stack[ topofstack ] = value;
}

int pop( void )
{
	return stack[ topofstack-- ];
}

void printTopOfStack()
{
	if( topofstack == 0 )
		printf("\nNo element to pop !");
	else
		printf("\n%d\n", stack[ topofstack ]);
}

void swapPenultimateAndTopElements()
{
	int temp;

	if( topofstack == 0 )
		printf("\nSwap not possible !");
	else
	{
		temp = stack[ topofstack ];
		stack[ topofstack ] = stack[ topofstack - 1 ];
		stack[ topofstack - 1 ] = temp;
	}
}

void clearStack()
{
	int index = 0;

	while( index < topofstack )
	
		stack[ index++ ] = ' ';

	topofstack = 0;
}

void displayResult(int status)
{
	if( status == ERROR )
		printf("Error!");

	else
		printf("%d", stack[ topofstack ]);
}