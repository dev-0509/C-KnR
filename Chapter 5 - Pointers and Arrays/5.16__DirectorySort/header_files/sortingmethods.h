/* ------ MACROS ------ */

#define FOUND	0
#define NOT_FOUND	1

#define WILD_CHAR_FOUND	'!'

/* -------------------- */

/* --------------------------- FUNCTION HEADERS ------------------------------ */

void convertComparatorStringToLowerCase( char * , char * );

void convertComparableStringToLowerCase( char * , char * );

int compareStrings( char * , char * , int );

int compare( char , char  );

int directorySort( char * , char * );

int normalSort( char * , char * );

int compareAndSort( char , char , int * , int * );

int noWildCharFound( char , char , int ** , int ** );

/* ---------------------------------------------------------------------------- */