#include "stdio.h"
#include "ctype.h"
#include "../header_files/readlines.h"
#include "../header_files/sortingmethods.h"

int str_cmp(char * comparator_string, char * comparable_string, int directorysort_flag) {

	int index = 0;

	char lowercase_comparator[ MAXLENGTH ];
	char lowercase_comparable[ MAXLENGTH ];

	convertComparatorStringToLowerCase( comparator_string , lowercase_comparator);

	convertComparableStringToLowerCase( comparable_string , lowercase_comparable );

	return ( compareStrings( lowercase_comparator , lowercase_comparable , directorysort_flag ) ) ;

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

int compareStrings(char * comparator_string, char * comparable_string, int directorysort_flag) {

	int i = 0, j = 0, status;

	if( directorysort_flag == TRUE )

		return ( directorySort( comparator_string , comparable_string ) );

	else

		return ( normalSort( comparator_string , comparable_string ) );

}

int directorySort(char * comparator_string, char * comparable_string) {

	int index_1, index_2, status;

	index_1 = index_2 = 0;

	while( *( comparator_string + index_1 ) != '\0' ) {

		if( noWildCharFound( *( comparator_string + index_1 ) , *( comparable_string + index_2 ) , &index_1 , &index_2 ) ) {

			status = compare( *( comparator_string + index_1 ) , *( comparable_string + index_2 ) );

			( ++index_1 ) ;	( ++index_2 ) ;

			if( status != 0 )

				return status;			

		}

	}

	return status;

}

int noWildCharFound(char main_char, char cmp_char, int * index_1, int * index_2) {

	if( isalpha( main_char ) || isdigit( main_char ) ) {

		if( isalpha( cmp_char ) || isdigit( cmp_char ) )

			return NOT_FOUND;

		else

			++(*index_2);

	} else

		++(*index_1);

	return FOUND;

}

int normalSort(char * comparator_string, char * comparable_string) {

	int index = 0, status;

	while( *(comparator_string + index) != '\0' ) {

		status = compare( *( comparator_string + index ) , *( comparable_string + index ) );

		if( status != 0 )

			return status;

		++index;

	}

	return status;

}

int compare(char main_char, char cmp_char) {

	if( cmp_char == '\0' )

		return 1;

	if( main_char < cmp_char )

		return -1;

	if( main_char > cmp_char )

		return 1;

	return 0;

}