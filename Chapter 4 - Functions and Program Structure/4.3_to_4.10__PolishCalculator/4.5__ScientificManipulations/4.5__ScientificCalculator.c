#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#include "Global.h"

/*
	Polish Calculator : evaluates expressions by converting them into POSTFIX notations and 
						uses a Stack for arithmetic linking.

	Added Scientific Manipulations to handle operations like sine, cosine, exponential etc.
	and print the result accordingly.

PS: --Beta Version-- Deals with single-digit Operands only :p
*/

int main(int argc, char const * argv[])
{
	int status;
	char choice;

	populateBufferFromCmd( argc , argv );

	status = polishCalculator();

	displayResult( status );

	printf("\n\nScientific Manipulations ? (y/n) : ");
	choice = getchar();

	if( choice == 'y' )
		
		scientificCalculator();

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

void scientificCalculator()
{
	int choice, number;

	printf("\n\t1. Sine");
	printf("\n\t2. Cosine");
	printf("\n\t3. Tangent");
	printf("\n\t4. Exponential");
	printf("\n\t5. Logarithm");

	printf("\n\nEnter your choice (1-5) : ");
	scanf("%d", &choice);

	printf("\nNumber : ");
	scanf("%d", &number);

	switch( choice )
	{
		case 1 : printf("%lf\n", sin( number ));
				break;
		case 2 : printf("%lf\n", cos( number ));
				break;
		case 3 : printf("%lf\n", tan( number ));
				break;
		case 4 : printf("%lf\n", exp( number ));
				break;
		case 5 : printf("%lf\n", log( number ));
				break;
		default : printf("\nInvalid Choice !");
				break;
	}
}

void displayResult(int status)
{
	if( status == ERROR )
		printf("Error!");

	else
		printf("%d", stack[ topofstack ]);
}