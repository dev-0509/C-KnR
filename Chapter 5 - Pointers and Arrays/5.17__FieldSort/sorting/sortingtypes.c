#include "stdio.h"
#include "string.h"
#include "../header_files/readlines.h"
#include "../header_files/sorthandler.h"
#include "../header_files/fieldsortmethods.h"

int checkTypeOfSorting(int argc, char const * argv[], int * sorting_type) {

	int flag = OFF, reverse_sort = FALSE, numeric_sort = FALSE, directorysort_flag = FALSE;

	checkForDirectorySort( argc , argv , &directorysort_flag );

	*sorting_type = LEXICO_SORT;

	while( argc-- ) {

		if( strcmp( argv[ argc ] , "-r" ) == 0 ) {

			if( flag == ON )

				*sorting_type = REVERSE_NUMERIC_SORT;

			else {

				*sorting_type = REVERSE_SORT;

				flag = ON;

			}

		}

		if( strcmp( argv[ argc ] , "-n" ) == 0 ) {

			if( flag == ON )

				*sorting_type = REVERSE_NUMERIC_SORT;

			else {

				*sorting_type = NUMERIC_SORT;

				flag = ON;

			}

		}

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