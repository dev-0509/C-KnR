
//----------------------------------------------------- UTILITY METHODS ---------------------------------------------------//

#include "stdio.h"
#include "string.h"
#include "dateconversions.h"

int isDateValid(int day, int month, int yearday, int choice) {

	if( choice == 1 ) {

		if( day < 1 || day > 31 )

			return INVALID_DATE;

		if( month < JANUARY || month > DECEMBER )

			return INVALID_DATE;

	} else if( choice == 2 ) {

		if( yearday < 1 || yearday > 366 )

			return INVALID_DATE;

	}

	return VALID_DATE;

}

int checkForLeapYear(int * year) {

	*year = ( *year % 4 == 0 ) && 

		( *year % 100 != 0 ) || 

		( *year % 400 == 0 );	

}

char * month_array[] = { "january" , "february" , "march" , "april" , "may" ,"june" , 

			"july" , "august" , "september" , "october" , "november" , "december" };

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

//--------------------------------------------------------------------------------------------------------------------------//