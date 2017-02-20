#include "stdio.h"
#include "Global_Parameters.h"

char program[500];

int readProgram()
{
	int index = 0;

	while((c = getchar()) != EOI)
		program[index++] = c;

	return index;
}

void displayProgram(int index)
{
	int i = 0;

	printf("\n# Program after removal of comments : \n\n");

	while(i < index)
		printf("%c", program[i++]);
}

int main()
{
	int i = 0, index, flag = 0;

	printf("\n# Enter the C-Program : \n\n");

	index = readProgram();

	while(i < index)
	{
		if(program[i] == '/')
		{
			program[i] = ' ';
			++flag;

			if(flag == 2)
			{
				while(program[i] != '\n')
					program[i++] = ' ';
			}
			else
				++i;
		}
		else if(program[i] == '*')
		{
			flag = 0;
			program[i++] = ' ';

			while(1)
			{
				if(program[i] == '*' && program[i + 1] == '/')
				{
					program[i] = program[i + 1] = ' ';
					break;
				}	

				program[i++] = ' ';
			}
		}
		else
		{
			flag = 0;
			++i;
		}
	}

	displayProgram(index);

	return 0;
}