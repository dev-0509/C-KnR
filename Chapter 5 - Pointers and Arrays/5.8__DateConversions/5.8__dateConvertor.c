#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "dateconversions.h"

void displayResult(int result) {

	if( result == INVALID_DATE ) {

		printf("\nPlease enter a valid date!\n\n");

		return;

	}

	else if( result == SUCCESS )

		return;

	printf("\nDay of Year: %d\n\n", result);

}

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

int fetchDate(int * date, int * month, int * year, int * yearday, int choice) {

	char month_name[ 20 ];

	system( "clear" );

	if( choice == 1 ) {

		printf("\nEnter Date: ");
		scanf( "%d" , date );

		printf("\nEnter Month: ");
		scanf( "%s" , month_name );

		printf("\nEnter Year: ");
		scanf( "%d" , year );

		*month = fetchMonthNumber( month_name );

	} else if( choice == 2 ) {

		printf("\nEnter Year: ");
		scanf( "%d" , year );

		printf("\nEnter Day in the Year: ");
		scanf( "%d" , yearday );

	}

	if( isDateValid( *date , *month , *yearday , choice ) )

		return VALID_DATE;

	else 

		return INVALID_DATE;

}

int printMenu() {

	int choice;

	system( "clear" );

	printf("\n\t1. Detect Day of the Year from Month | Date");
	printf("\n\t2. Detect Month | Date from Day of the Year");

	printf("\n\nSelection ? : ");
	scanf( "%d" , &choice );

	return choice;

}

int main(int argc, char const *argv[]) {

	int choice, result;

	choice = printMenu();

	result = dateConvertor( choice );

	displayResult( result );

	return 0;

}