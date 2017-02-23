// MACROS

#define EOI '%'
#define MAXLENGTH 100

// VARIABLES

char c;
char program[500];


// FUNCTIONS

int getLine(char buffer[])
{
	int i = 0, flag = 0;
	
	while( ((c = getchar()) != EOI) && (c != '\n') && (i < MAXLENGTH) )
	{
		buffer[i++] = c;
		flag = 1;
	}

	buffer[i] = '\0';

	if(c == '\n')
		buffer[++i] = c;

	if(flag == 1)
		return 1;
	else
		return 0;
}

void clearBuffer(char buffer[])
{
	char i = 0;

	while(i < MAXLENGTH)
		buffer[i++] = ' ';
}

void displayLine(char buffer[])
{
	int index = 0;

	while(buffer[index] != '\0')
		printf("%c", buffer[index++]);

	printf("\n");
}