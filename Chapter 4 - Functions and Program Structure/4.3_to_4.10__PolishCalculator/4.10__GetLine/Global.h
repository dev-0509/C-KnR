//------ MACROS --------//

#define BUFFSIZE 	100 
#define MAXSIZE		50
#define NUMBER		'0'
#define ERROR		'X'
#define SUCCESS		'$'

//-------------- HEADERS -----------------//

char polishCalculator( void );
char getOp( char * );
void getLineIntoBufferFromCmd( int , char const * [] );
char get_ch( void );
void push( int );
int pop( void );
void displayResult( int );

//----------------------------------------//