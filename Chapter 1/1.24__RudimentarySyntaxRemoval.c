#include "stdio.h"
#include "Global_Parameters.h"

int readProgram()
{
	int index = 0;

	while((c = getchar()) != EOI)
		program[index++] = c;

	return index;
}

int checkDoubleQuotes(int index)
{
	while(program[index] != '\n')
	{
		if(program[index] == '"')
			break;
		else
			++index;
	}

	if(program[index] == '\n')
		return 0;
	else
		return 1;
}

int checkSingleQuotes(int index)
{
	while(program[index] != '\n')
	{
		if(program[index] == '\'')
			break;
		else
			++index;
	}

	if(program[index] == '\n')
		return 0;
	else
		return 1;
}

/* 
int checkComments()
{	
}
*/

int main()
{
	int i = 0, index, parenthesis, braces, brackets, doublequotes, singlequotes, doublequotestatus, singlequotestatus;

	parenthesis = brackets = braces = doublequotes = singlequotes = 0;

	printf("\n# Enter the C-Program : \n\n");

	index = readProgram();

	while(i < index)
	{
		if(program[i] == '(')
			++parenthesis;
		else if(program[i] == '{')
			++braces;
		else if(program[i] == '[')
			++brackets;

		else if(program[i] == ')')
			--parenthesis;
		else if(program[i] == '}')
			--braces;
		else if(program[i] == ']')
			--brackets;

		else
		{
			if(program[i] == '"')
				doublequotestatus = checkDoubleQuotes(i);
			else if(program[i] == '\'')
				singlequotestatus = checkSingleQuotes(i);
			// else
				// commentstatus = checkComments();
		}

		++i;
	}

	if( (parenthesis != 0) || (braces != 0) || (brackets != 0) )
		printf("\n\n\tRudimentary Syntax detected ! Erroneous Code");
	else
	{
		if( (singlequotestatus) && (doublequotestatus) )
			printf("\n\n\tNo Rudimentary Syntax :)");
	}

	return 0;
}