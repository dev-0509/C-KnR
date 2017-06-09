
#include "stdio.h"
#include "stdlib.h"
#include "dateconversions.h"


//----------------------------------------------------- INPUT ---------------------------------------------------//

int fetchDate(int * date, int * month, int * year, int * yearday, int choice) {

	char month_name[ 20 ];

	system( "clear" );

	printf("\nEnter Year: ");
	scanf( "%d" , year );

	if( choice == 1 ) {

		printf("\nEnter Date: ");
		scanf( "%d" , date );

		printf("\nEnter Month: ");
		scanf( "%s" , month_name );

		*month = fetchMonthNumber( month_name );

	} else if( choice == 2 ) {

		printf("\nEnter Day in the Year: ");
		scanf( "%d" , yearday );

	}

	if( isDateValid( *date , *month , *yearday , choice ) )

		return VALID_DATE;

	else 

		return INVALID_DATE;

}

//--------------------------------------------------------------------------------------------------------------------------//


//----------------------------------------------------- OUTPUT ---------------------------------------------------//

void displayResult(int result) {

	if( result == INVALID_DATE ) {

		printf("\nPlease enter a valid date!\n\n");

		return;

	}

	else if( result == SUCCESS )

		return;

	printf("\nDay of Year: %d\n\n", result);

}

//--------------------------------------------------------------------------------------------------------------------------//