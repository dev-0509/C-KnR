// MACROS

#define MAXSIZE 			200
#define END_OF_FILE(p) 		!(feof(p))
#define READ				"r"

#define NOT_UPPERCASE(c)	c<'A'||c>'Z'
#define NOT_LOWERCASE(c)	c<'a'||c>'z'
#define NOT_NUMBER(c)		c<'0'||c>'9'

#define NOTFOUND 			0
#define TRUE				1
#define FALSE				0

// VARIABLES

char buffer[MAXSIZE];
char outputbuffer[MAXSIZE];

char filename[] = "C:\\Users\\devsa\\Desktop\\Study !\\Programs\\C-KnR\\Chapter 3 - Control Flow\\3.3__Expand-ShorthandNotations\\3.3_Input.txt";

char start_char, end_char, leading_special_char;
char special_char;

int i = 0;
int out_buf_index = 0;

// FUNCTIONS

void clearBuffers()
{
	int index = 0;

	while( index < out_buf_index )
	{
		buffer[index] = outputbuffer[index] = ' ';

		++index;
	}

	out_buf_index = i = 0;
}