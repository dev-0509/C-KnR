#include "stdio.h"
#include "string.h"
#include "dateconversions.h"

static char daytab[ 2 ][ 13 ] = { 

	{ 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } , 

	{ 0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }

};

int dateConvertor(int choice) {

	int status, month, date, year, yearday;
	char month_name[ 20 ];

	status = fetchDate( &date , &month , &year , &yearday , choice );

	if( status == INVALID_DATE )

		return INVALID_DATE;

	switch( choice ) {

		case 1:	date = identifyDayOfYear( date , month , year );

			return date;

		case 2:	year = identifyMonthAndDate( year , yearday , &month , &date );

			strcpy( month_name , ( fetchMonthName( month ) ) );

			printf("\nMonth: %s\nDate: %d\n\n", month_name, date);

			break;

		default: printf("\nInvalid Choice!\n\n");

	}

	return SUCCESS;

}

int identifyDayOfYear(int day, int month, int year) {

	int month_number, leap_year;

	leap_year = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for( month_number = 1 ; month_number < month ; ++month_number )

		day += daytab[ leap_year ][ month_number ];

	return day;	

}

int identifyMonthAndDate(int year, int yearday, int * month, int * date) {

	int month_number, leap_year;

	leap_year = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for( month_number = 1 ; yearday > daytab[ leap_year ][ month_number ] ; 

														++month_number )

		yearday -= daytab[ leap_year ][ month_number ];

	*month = month_number;

	*date = yearday;

}