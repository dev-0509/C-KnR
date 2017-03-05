#include "stdio.h"
#include "stdlib.h"
#include "Global_Parameters.h"

char buffer[MAXLENGTH];

int readFile(const char *fname)
{
	int index = 0;
	FILE *fptr;

	fptr = fopen(fname, "r");

	while((c = fgetc(fptr)) != EOF)
		buffer[index++] = c;

	buffer[index] = '\0';

	// printf("%s", buffer);

	return index;
}

void displayProgram(int index)
{
	int i = 0;

	printf("\n# Program after removal of comments : \n\n");

	while(i < index)
		printf("%c", program[i++]);
}

int isCommentValid(int position, int programindex, int startofcomment, int endofcomment)
{
	int index ,doublequoteindex;

	if(endofcomment == 0)
	{
		while(position < programindex)
		{
			if(program[position] == '\n')
				break;

			if(program[position] == 'p')
			{
				if(program[position + 1] == 'r')
				{
					if(program[position + 2] == 'i')
					{
						if(program[position + 3] == 'n')
						{
							if(program[position + 4] == 't')
							{
								if(program[position + 5] == 'f')
								{
									if(program[position + 6] == '(')
									{
										if(startofcomment < position)
											return 1;

										if(program[position + 7] == '"')
										{
											index = doublequoteindex = 	position + 7;
											index++;

											while( program[index] != '"' )
											{
												if(program[index] == '\n')
												{
													if(startofcomment > index)
														return 1;
												}	

												++index;
											}	

											if(startofcomment > index) 
												return 1;
											else 
												return 0;
										}
										else
											++position;
									}
									else
										++position;
								}
								else
									++position;
							}
							else
								++position;
						}
						else
							++position;
					}
					else
						++position;
				}
				else
					++position;	
			}
			else
				++position;
		}
	}
	else
	{
		while(position < programindex)
		{
			if(program[position] == '\n')
				break;

			if(program[position] == 'p')
			{
				if(program[position + 1] == 'r')
				{
					if(program[position + 2] == 'i')
					{
						if(program[position + 3] == 'n')
						{
							if(program[position + 4] == 't')
							{
								if(program[position + 5] == 'f')
								{
									if(program[position + 6] == '(')
									{
										if(startofcomment < position)
											return 1;

										if(program[position + 7] == '"')
										{
											index = doublequoteindex = 	position + 7;
											index++;

											while( program[index] != '"' )
											{
												if(program[index] == '*' && program[index + 1] == '/')
												{
													if( startofcomment > doublequoteindex && endofcomment == (index + 1) )
														return 0;
												}	

												if(index == programindex)
													return 0;

												++index;
											}	

											if(startofcomment > doublequoteindex && endofcomment < index) 
												return 0;
											else 
												return 1;
										}
										else
											++position;
									}
									else
										++position;
								}
								else
									++position;
							}
							else
								++position;
						}
						else
							++position;
					}
					else
						++position;
				}
				else
					++position;	
			}
			else
				++position;
		}	
	}

	return 1;
}

int main()
{
	int i = 0, pos, index, startindex, endindex, closeblock = 0, newline, j, iscomment = 0, endofcomment;

	// printf("\n# Enter the C-Program : \n\n");

	char fname[] = "C:\\Users\\devsa\\Desktop\\Study !\\Projects\\ITS_UICC_OS_its mine!\\ITS_UICC_OS_3G\\ITS_UICC_OS\\dev\\src\\framework\\fw_Authenticate.c";
	index = readFile(fname);

	//exit(0);

	while(i < index)
	{
		if(program[i] == '/')
		{
			++iscomment;

			if(iscomment == 2)
			{
				pos = i;

				while(program[pos] != '\n')
					--pos;

				if( isCommentValid( (pos + 1) , index , (i - 1) , 0) )
				{
					program[i - 1] = ' ';

					while(program[i] != '\n')
						program[i++] = ' ';
				}
				else
					++i;
			}
			else
				++i;
		}
		else if(program[i] == '*')
		{
			if(iscomment == 1)
			{
				pos = i;

				while(program[pos] != '\n')
					--pos;

				iscomment = 0;
				startindex = i - 1;

				while(1)
				{
					if( !(closeblock == 1) )
					{
						if(program[i] == '\n')
						{
							closeblock = 1;
							newline = i;
						}
					}

					if(i == index)
					{
						i = newline + 1;
						endofcomment = 0;
						break;
					}

					if(program[i] == '/' && program[i + 1] == '*')
					{
						if(closeblock == 1)
						{
							i = newline + 1;
							endofcomment = 0;
							break;
						}
						else
						{
							while(program[i++] != '\n');

							endofcomment = 0;
							break;
						}
					}

					if(program[i] == '*' && program[i + 1] == '/')
					{
						endindex = i + 1;

						endofcomment = 1;
				
						break;
					}	

					i++;
				}

				closeblock = 0;

				if(endofcomment == 0)
					continue;
				else if(endofcomment == 1)
				{
					if( isCommentValid( (pos + 1) , index , startindex , endindex) )
					{
						for(j = startindex; j <= endindex; j++)
							program[j] = ' ';
					}
					else
						++i;
				}
			}
		}
		else
		{
			if(iscomment == 1)
				program[i - 1] = '/';

			iscomment = 0;
			++i;
		}
	}

	displayProgram(index);

	return 0;
}