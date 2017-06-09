
// ---------------- MACROS ----------------//

#define INVALID_DATE		0
#define VALID_DATE			1
#define INVALID_MONTH_NAME	0
#define SUCCESS				'%'

#define JANUARY				1
#define DECEMBER			12

//-----------------------------------------//


// ---------------- FUNCTIONS HEADERS ---------------------//

int dateConvertor( int );

int fetchDate(int * , int * , int * , int * , int );

int identifyDayOfYear( int , int , int );

int identifyMonthAndDate( int , int , int * , int * );

int fetchDate( int * , int * , int * , int * , int );

int isDateValid( int , int , int , int );

int fetchMonthNumber( char * );

char * fetchMonthName( int );

//---------------------------------------------------------//