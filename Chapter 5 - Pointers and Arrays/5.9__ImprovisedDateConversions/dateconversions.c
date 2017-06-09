#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dateconversions.h"

static char daytab[ 2 ][ 13 ] = { 

	{ 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } , 

	{ 0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }

};

int dateConvertor(int choice) {

	int status, month, date, year, yearday;
	char month_name[ 20 ];

	int copy_year;

	status = fetchDate( &date , &month , &year , &yearday , choice );

	copy_year = year;

	if( status == INVALID_DATE )

		return INVALID_DATE;

	switch( choice ) {

		case 1:	date = identifyDayOfYear( date , month , year );

			return date;

		case 2:	identifyMonthAndDate( year , yearday , &month , &date );

			strcpy( month_name , ( fetchMonthName( month ) ) );

			printf("\nHere's your Date: ");

			printf("%s %d, %d\n\n", month_name, date, copy_year);

			break;

		default: printf("\nInvalid Choice!\n\n");

	}

	return SUCCESS;

}

int identifyDayOfYear(int day, int month, int year) {

	int month_number;

	checkForLeapYear( &year );

	for( month_number = 1 ; month_number < month ; ++month_number )

		day += * ( * ( daytab + year ) + month_number );

	return day;	

}

void identifyMonthAndDate(int year, int yearday, int * month, int * date) {

	int month_number;

	checkForLeapYear( &year );

	for( month_number = 1 ; yearday > * ( * ( daytab + year ) + month_number ) ; 

									++month_number )

		yearday -= * ( * ( daytab + year ) + month_number );

	*month = month_number;

	*date = yearday;

}