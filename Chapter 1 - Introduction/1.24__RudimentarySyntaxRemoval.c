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
	int flag = 0;

	while(program[index] != '\n')
	{
		if(program[index] == 34)
		{
			flag = 1;
			break;
		}	
		else
			++index;
	}

	if(program[index] == '\n')
	{
		if(flag == 0)
			return 1;
		else
			return 0;	
	}
	else
		return 1;
}

int checkSingleQuotes(int index)
{
	int flag = 0;

	while(program[index] != '\n')
	{
		if(program[index] == 39)
		{
			flag = 1;
			break;
		}
		else
			++index;
	}

	if(program[index] == '\n')
	{
		if(flag == 0)
			return 1;
		else
			return 0;	
	}
	else
		return 1;
}

int checkComments(int programindex)
{
	int i = 0;

	while(i < programindex)
	{
		if(program[i] == '/')
		{
			if(program[i + 1] == '/')
				return 1;

			else if(program[i + 1] == '*')
			{
				i = i + 2;

				while(1)
				{
					if(program[i] == '*' && program[i + 1] == '/')
						return 1;

					++i;

					if(i == programindex)
						return 0;
				}
			}

			else
				++i;
		}
		else
			++i;
	}	

	return 1;
}


int main()
{
	int i = 0, flag = 0, index, parenthesis, braces, brackets, doublequotes, singlequotes, doublequotestatus, singlequotestatus, commentstatus;

	parenthesis = brackets = braces = doublequotes = singlequotes = 0;

	printf("\n# Enter the C-Program %d: \n\n", singlequotestatus);

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
			{
				flag = 1;
				doublequotestatus = checkDoubleQuotes(i);
			}

			else if(program[i] == '\'')
			{
				flag = 1;
				singlequotestatus = checkSingleQuotes(i);
			}

			else
				commentstatus = checkComments(index);
		}

		++i;
	}

	if( (parenthesis != 0) || (braces != 0) || (brackets != 0) )
		printf("\n\n\tRudimentary Syntax detected ! Erroneous Code");
	else
	{
		if(flag == 1)
		{
			if( (singlequotestatus) && (doublequotestatus) )
				printf("\n\n\tNo Rudimentary Syntax :)");
			else
				printf("\n\n\tRudimentary Syntax detected ! Erroneous Code");	
		}
		else
		{
			if(commentstatus)
				printf("\n\n\tNo Rudimentary Syntax :)");
			else
				printf("\n\n\tRudimentary Syntax detected ! Erroneous Code");		
		}
	}

	return 0;
}