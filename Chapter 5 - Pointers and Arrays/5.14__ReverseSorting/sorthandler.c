#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "readlines.h"
#include "sorthandler.h"

void checkTypeOfSorting(int argc, char const * argv[], int * sorting_type) {

	int reverse_sort = FALSE, numeric_sort = FALSE;

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

void sortHandler(int sorting_type, char * lines[], int no_of_lines) {

	int left, right;

	left = 0;	right = ( no_of_lines - 1 );

	quickSort( lines , left , right , sorting_type );

}

void quickSort(char * lines[], int left, int right, int sorting_type) {

	int index, mid, last;

	void ( * func_ptr )( char * [] , int * , int , int );

	setTypeOfSorting( sorting_type , &func_ptr );

	if( left >= right )

		return;

	mid = ( ( left + right ) / 2 );

	swap( lines , left , mid );

	last = left;

	for( index = ( left + 1 ) ; index <= right ; ++index )

		( *func_ptr )( lines , &last , left , index );

	swap( lines , left , last );

	quickSort( lines , left , ( last - 1 ) , sorting_type );

	quickSort( lines , ( last + 1 ) , right , sorting_type );

}

void setTypeOfSorting(int sorting_type, void ( ** func_ptr )(char * [], int *, int, int)) {

	switch( sorting_type ) {

		case LEXICO_SORT :	*func_ptr = lexicographicSort;

					break;

		case REVERSE_SORT :	*func_ptr = reverseSort;

					break;

		case NUMERIC_SORT :	*func_ptr = numericSort;

					break;

	case REVERSE_NUMERIC_SORT :	*func_ptr = reverseNumericSort;

					break;

	}

}

void lexicographicSort(char * lines[], int * last, int left, int index) {

	if( strcmp( lines[ index ] , lines[ left ] ) < 0 )

		swap( lines , ++( *last ) , index );	

}

void reverseSort(char * lines[], int * last, int left, int index) {

	if( strcmp( lines[ index ] , lines[ left ] ) > 0 )

		swap( lines , ++( *last ) , index );

}

void numericSort(char * lines[], int * last, int left, int index) {
	
	if( numberCompare( lines[ index ] , lines[ left ] ) < 0 )

		swap( lines , ++( *last ) , index );

}

void reverseNumericSort(char * lines[], int * last, int left, int index) {
	
	if( numberCompare( lines[ index ] , lines[ left ] ) > 0 )

		swap( lines , ++( *last ) , index );

}

int numberCompare(char * line1, char * line2) {

	int value1, value2;

	value1 = atoi( line1 );		value2 = atoi( line2 );

	if( value1 < value2 )

		return -1;

	if( value1 > value2 )

		return 1;

	return 0;

}

void swap(char * lines[], int left, int right) {

	char * temp;

	temp = lines[ left ];

	lines[ left ] = lines[ right ];

	lines[ right ] = temp;

}