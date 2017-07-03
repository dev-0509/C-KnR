#include "stdio.h"
#include "string.h"
#include "../header_files/readlines.h"
#include "../header_files/sorthandler.h"

int checkTypeOfSorting(int argc, char const * argv[], int * sorting_type) {

	int reverse_sort = FALSE, numeric_sort = FALSE, directorysort_flag = FALSE;

	checkForDirectorySort( argc , argv , &directorysort_flag );

	switch( argc ) {

		case 1 :	*sorting_type = LEXICO_SORT;

				break;

		case 2 :	if( ! ( strcmp( argv[ 1 ] , "-r" ) ) )

					*sorting_type = REVERSE_SORT;

				else if( ! (strcmp( argv[ 1 ] , "-n" ) ) )

					*sorting_type = NUMERIC_SORT;

				else

					*sorting_type = LEXICO_SORT;

				break;

		case 3 :	if( ! (strcmp( argv[ 1 ] , "-r" ) ) || 

				! (strcmp( argv[ 2 ] , "-r" ) ) )

					reverse_sort = TRUE;

				if( ! (strcmp( argv[ 1 ] , "-n" ) ) || 

				! (strcmp( argv[ 2 ] , "-n" ) ) )

					numeric_sort = TRUE;

				*sorting_type = ( type( reverse_sort , numeric_sort ) );

				break;

		default :	*sorting_type = LEXICO_SORT;

	}

	return directorysort_flag;

}

void checkForDirectorySort(int argc, char const * argv[], int * flag) {

	while( argc-- ) {

		if( ( strcmp( argv[ argc ] , "-d" ) ) == 0 ) {

			*flag = TRUE;

			return;

		}

	}

}

int type(int reverse_sort, int numeric_sort) {

	if( reverse_sort == TRUE && numeric_sort == TRUE )

		return REVERSE_NUMERIC_SORT;

	if( reverse_sort == TRUE )

		return REVERSE_SORT;

	if( numeric_sort == TRUE )

		return NUMERIC_SORT;

	return LEXICO_SORT;

}