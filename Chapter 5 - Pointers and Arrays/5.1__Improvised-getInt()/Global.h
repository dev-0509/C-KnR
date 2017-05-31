//------ MACROS --------//

#define MAXLENGTH 		100 
#define NOT_A_NUMBER	0
#define NO_NUMBER 		'X'
#define PRESENT			1
#define NOT_PRESENT		0

//-------------- HEADERS -----------------//

void getStringFromCmd( int , char const * [] , char [] );
int getInt( char [] , int * );
char get_ch( char [] );
void unget_ch( char );
void displayResult( int , int );

//----------------------------------------//