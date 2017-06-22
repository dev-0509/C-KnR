/* ---------------------------------------- MACROS ----------------------------------------- */

#define SUCCESS	1
#define READ		"r"
#define NEWLINE 	'\n'
#define OVERFLOW	-1
#define STORAGE_AVAILABLE	0
#define STORAGE_NOT_AVAILABLE	-1
#define TRUE	1
#define FALSE	0

#define MAXLINES	100
#define MAXLENGTH	100

#define NEW_CHARACTER_EXISTS( character , fptr ) ( character = fgetc( fptr ) ) != NEWLINE

#define LINE_EXISTS( newline , length )	( ( length = getLine( newline ) ) > 0 )

/* ----------------------------------------------------------------------------------------- */


/* -------------- FUNCTIONS HEADERS ------------------- */

// Input | Output
void printSortedLines( char * [] , int , int );

void printTypeOfSorting( int );

void printLineIndex( int );


// Read Lines
int populateBufferFromFile( char * [] , int * );

int getLine( char * );

void storeLine( char * [] , int ** , char * , char * );


// Utility
void openFile( FILE ** );

void fetchMemoryForStorage( char ** , int );

int checkOverflow( int );

void checkMemoryStatus( int );

/* ----------------------------------------------------- */