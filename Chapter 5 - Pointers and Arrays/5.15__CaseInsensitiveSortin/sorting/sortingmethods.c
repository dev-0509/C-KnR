#include "stdio.h"
#include "ctype.h"
#include "../header_files/readlines.h"
#include "../header_files/sortingmethods.h"

int str_cmp(char * comparator_string, char * comparable_string) {

	int index = 0;

	char lowercase_comparator[ MAXLENGTH ];
	char lowercase_comparable[ MAXLENGTH ];

	convertComparatorStringToLowerCase( comparator_string , lowercase_comparator);

	convertComparableStringToLowerCase( comparable_string , lowercase_comparable );

	return ( compareStrings( lowercase_comparator , lowercase_comparable ) ) ;

}

void convertComparatorStringToLowerCase(char * comparator_string, char * lowercase_comparator) {

	while( *comparator_string != '\0' ) {

		if( *comparator_string >= 'A' && *comparator_string <= 'Z' ) {

			*lowercase_comparator = tolower( *comparator_string );

			( lowercase_comparator++ ) ;	( comparator_string++ ) ;

			continue;

		}

		*lowercase_comparator = *comparator_string;

		( lowercase_comparator++ ) ;	( comparator_string++ ) ;

	}

}

void convertComparableStringToLowerCase(char * comparable_string , char * lowercase_comparable ) {

	while( *comparable_string != '\0' ) {

		if( *comparable_string >= 'A' && *comparable_string <= 'Z' ) {

			*lowercase_comparable = tolower( *comparable_string );

			( lowercase_comparable++ ) ;	( comparable_string++ ) ;

			continue;

		}

		*lowercase_comparable = *comparable_string;

		( lowercase_comparable++ ) ;	( comparable_string++ ) ;

	}

}

int compareStrings(char * comparator_string, char * comparable_string) {

	int index = 0;

	while( *(comparator_string + index) != '\0' ) {

		if( *( comparable_string + index ) == '\0' )

			return 1;

		if( *( comparator_string + index ) < *( comparable_string + index ) )

			return -1;

		if( *( comparator_string + index ) > *( comparable_string + index ) )

			return 1;

		++index;

	}

	return 0;

}