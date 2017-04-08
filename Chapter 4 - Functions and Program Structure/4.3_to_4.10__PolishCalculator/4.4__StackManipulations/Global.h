//------ MACROS --------//

#define BUFFSIZE 	100 
#define MAXSIZE		50
#define NUMBER		'0'
#define ERROR		'X'
#define SUCCESS		'$'

//-------------- HEADERS -----------------//

char polishCalculator( void );
char getOp( char * );
void populateBufferFromCmd( int , char const * [] );
char get_ch( void );
void unget_ch( char );
void stackHandler();
void push( int );
int pop( void );
void printTopOfStack();
void swapPenultimateAndTopElements();
void clearStack();
void displayResult( int );

//----------------------------------------//