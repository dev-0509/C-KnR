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