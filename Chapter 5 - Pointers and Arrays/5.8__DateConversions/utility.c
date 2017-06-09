// ----------------- UTILITY METHODS ------------------------//

#include "stdio.h"
#include "string.h"
#include "dateconversions.h"

char *month_array[] = { "january" , "february" , "march" , "april" , "may" ,

					"june" , "july" , "august" , "september" , "october" , 

					"november" , "december" };

int fetchMonthNumber(char * month_name) {

	int month_number = 0;

	while( ( strcmp( month_array[ month_number ] , month_name ) ) != 0 ) {

		if( ( month_number + 1 ) == DECEMBER )

			return INVALID_MONTH_NAME;

		++month_number;

	}

	return ( ++month_number );

}

char * fetchMonthName(int month_number) {

	return ( month_array[ --month_number ] );

}

//-----------------------------------------------------------//