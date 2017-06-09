
/* ---------------- MACROS ----------------*/

#define INVALID_DATE		0
#define VALID_DATE			1
#define INVALID_MONTH_NAME	0
#define SUCCESS				'%'

#define JANUARY				1
#define DECEMBER			12

/*-----------------------------------------*/


/* ---------------- FUNCTIONS HEADERS --------------------- */

// Input | Output
int fetchDate(int * , int * , int * , int * , int );

void displayResult( int );

// Date Conversions
int dateConvertor( int );

int identifyDayOfYear( int , int , int );

void identifyMonthAndDate( int , int , int * , int * );

// Utility
int isDateValid( int , int , int , int );

int checkForLeapYear( int * );

int fetchMonthNumber( char * );

char * fetchMonthName( int );

/* --------------------------------------------------------- */