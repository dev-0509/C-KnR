/* --------- MACROS --------- */

#define INVALID_FIELD	0

#define VALID	1
#define INVALID	0

/* -------------------------- */


/* ---------------- FUNCTION HEADERS ----------------- */

void fetchFieldNumberToSort( int , char const * [] , char * [] , int * );

int isFieldValid( char * , int );

void fetchStringsInField( char * , char * , char * , char * , int );

void fetchFieldStringInComparator( char * , char * , int );

void fetchFieldStringInComparable( char * , char * , int );

void getString( char * , char * );

/* --------------------------------------------------- */