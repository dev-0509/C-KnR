#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "../header_files/fieldsortmethods.h"

void fetchFieldNumberToSort(int argc , char const * argv[], char * lines[], int * field_no) {

	char string[ 5 ];	

	while( argc-- ) {

		strcpy( string , argv[ argc ] );

		if( isdigit( string[ 1 ] ) ) {

			*field_no = string[ 1 ] - '0';

			break;

		}

	}

	if( isFieldValid( lines[ 0 ] , *field_no ) )

		return;

	*field_no = INVALID_FIELD;

}

int isFieldValid(char * string, int field_no) {

	int local_field_count = 0, length;

	length = strlen( string );

	while( length-- ) {

		if( *string == ' ' )

			++local_field_count;

		++string;

	}

	if( field_no <= ( local_field_count + 1 ) )

		return VALID;

	else

		return INVALID;

}

void fetchStringsInField(char * comparator_string, char * comparable_string, char * main_fieldstring, char * cmp_fieldstring, int field_no) {

	fetchFieldStringInComparator( comparator_string , main_fieldstring , field_no );

	fetchFieldStringInComparable( comparable_string , cmp_fieldstring , field_no );

}

void fetchFieldStringInComparator(char * comparator_string, char * main_fieldstring, int field_no) {

	int space_count = 0;

	while( *comparator_string != '\0' ) {

		if( *comparator_string == ' ' )

			++space_count;

		if( space_count == ( field_no - 1 ) ) {

			getString( comparator_string , main_fieldstring );

			return;

		}

		++comparator_string;

	}

}

void fetchFieldStringInComparable(char * comparable_string, char * cmp_fieldstring, int field_no) {

	int space_count = 0;

	while( *comparable_string != '\0' ) {

		if( *comparable_string == ' ' )

			++space_count;

		if( space_count == ( field_no - 1 ) ) {

			getString( comparable_string , cmp_fieldstring );

			return;

		}

		++comparable_string;

	}

}

void getString(char * main_string, char * target_string) {

	if( *main_string == ' ' )

		++main_string;

	while( *main_string != ' ' ) {

		if( *main_string == '\0' )

			break;

		*target_string++ = *main_string++;

	}

	*target_string = '\0';

}