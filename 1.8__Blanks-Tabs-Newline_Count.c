#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *p; 
	char c, tabs = 0, newLines = 0, spaces = 0;
	p = fopen("C:\\TurboC4\\TC\\BIN\\tst.txt","r");

	while((c = fgetc(p)) != EOF)
	{
		if(c == ' ')
			spaces++;
		else if(c == '\t')
			tabs++;
		else if(c == '\n')
			newLines++;
		else
			continue;
	}

	printf("Number of Spaces : %d\nNumber of Tabs : %d\nNumber of Lines : %d", spaces, tabs, (newLines+1));
	
	fclose(p);	
	getch();	
}