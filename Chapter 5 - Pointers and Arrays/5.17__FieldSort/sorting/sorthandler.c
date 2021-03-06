#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "../header_files/readlines.h"
#include "../header_files/sorthandler.h"
#include "../header_files/fieldsortmethods.h"

void sortHandler(int sorting_type, char * lines[], int no_of_lines, int directorysort_flag, int field_no) {

	int left, right;

	left = 0;	right = ( no_of_lines - 1 );

	quickSort( lines , left , right , sorting_type , directorysort_flag , field_no );

}

void quickSort(char * lines[], int left, int right, int sorting_type, int directorysort_flag, int field_no) {

	int index, mid, last;

	void ( * func_ptr )( char * [] , int * , int , int , int , int );

	setTypeOfSorting( sorting_type , &func_ptr );

	if( left >= right )

		return;

	mid = ( ( left + right ) / 2 );

	swap( lines , left , mid );

	last = left;

	for( index = ( left + 1 ) ; index <= right ; ++index )

		( *func_ptr )( lines , &last , left , index , directorysort_flag , field_no );

	swap( lines , left , last );

	quickSort( lines , left , ( last - 1 ) , sorting_type , directorysort_flag , field_no );

	quickSort( lines , ( last + 1 ) , right , sorting_type , directorysort_flag , field_no );

}

void setTypeOfSorting(int sorting_type, void ( ** func_ptr )(char * [], int *, int, int , int , int )) {

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

void lexicographicSort(char * lines[], int * last, int left, int index, int directorysort_flag, int field_no) {

	if( str_cmp( lines[ index ] , lines[ left ] , directorysort_flag , field_no ) < 0 )

		swap( lines , ++( *last ) , index );	

}

void reverseSort(char * lines[], int * last, int left, int index, int directorysort_flag, int field_no) {

	if( str_cmp( lines[ index ] , lines[ left ] , directorysort_flag , field_no ) > 0 )

		swap( lines , ++( *last ) , index );

}

void numericSort(char * lines[], int * last, int left, int index, int directorysort_flag, int field_no) {

	int is_numerical = TRUE;
	
	if( numberCompare( lines[ index ] , lines[ left ] , &is_numerical , field_no ) == -1 )

		swap( lines , ++( *last ) , index );

	if( is_numerical == FALSE ) {

		if( str_cmp( lines[ index ] , lines[ left ] , directorysort_flag , field_no ) < 0 )

			swap( lines , ++( *last ) , index );

	}

}

void reverseNumericSort(char * lines[], int * last, int left, int index, int directorysort_flag, int field_no) {

	int is_numerical = TRUE;

	if( numberCompare( lines[ index ] , lines[ left ] , &is_numerical , field_no ) == 1 )

		swap( lines , ++( *last ) , index );

	if( is_numerical == FALSE ) {

		if( str_cmp( lines[ index ] , lines[ left ] , directorysort_flag , field_no ) > 0 )

			swap( lines , ++( *last ) , index );

	}

}

int numberCompare(char * line1, char * line2, int * is_numerical, int field_no) {

	int value1, value2;

	char main_fieldstring[ MAXLENGTH ];
	char cmp_fieldstring[ MAXLENGTH ];

	if( field_no != INVALID_FIELD ) {

		fetchStringsInField( line1 , line2 , main_fieldstring , cmp_fieldstring , field_no );

		value1 = atoi( main_fieldstring );		value2 = atoi( cmp_fieldstring );

	} else

		value1 = atoi( line1 );		value2 = atoi( line2 );

	if( value1 < value2 )

		return -1;

	if( value1 > value2 )

		return 1;

	if( value1 == 0 && value2 == 0 )

		*is_numerical = FALSE;

	return 0;

}

void swap(char * lines[], int left, int right) {

	char * temp;

	temp = lines[ left ];

	lines[ left ] = lines[ right ];

	lines[ right ] = temp;

}