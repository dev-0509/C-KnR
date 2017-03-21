#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "Global.h"

/*
	Polish Calculator : evaluates expressions by converting them into POSTFIX notations and 
						uses a Stack for arithmetic linking.

			Pushes each operand on to the stack, upon finding an operator, pops
			out the proper number of operands required for the operator, performs
			evaluation and stores the result on the Top of the Stack :)

PS: --Beta Version-- Deals with single-digit Operands only :p
*/

int main(int argc, char const * argv[])
{
	int status;

	populateBufferFromCmd( argc , argv );

	status = polishCalculator();

	displayResult( status );

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

void push(int value)
{
	++topofstack;

	stack[ topofstack ] = value;
}

int pop( void )
{
	return stack[ topofstack-- ];
}

void displayResult(int status)
{
	if( status == ERROR )
		printf("Error!");

	else
		printf("%d", stack[ topofstack ]);
}