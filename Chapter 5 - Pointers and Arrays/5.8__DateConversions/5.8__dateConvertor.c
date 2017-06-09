#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "dateconversions.h"

/*

=>	Program for Date Manipulations, fetches date according to the year specified and fetches
	the day of the year when month and day is supplied.

	Eg: For input, Date: 1 | Month: march

			Program identifies that 1st March is the 61st day of a Leap Year and
			60th day of a non-leap year.

		For input, Year: 2013 | Day of the Year: 60

			Program identifies that the 60th day in the year 2013 is 1st March


Happy Coding!:)

*/

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