#include "stdio.h"
#include "header_files/readlines.h"
#include "header_files/sorthandler.h"
#include "header_files/fieldsortmethods.h"

/*

=>	Program to Sort Strings read from a file, providing all types of sortings.

	~ Lexicographical Sorting
	~ Reverse Sorting
	~ Numeric Sorting

	A terminal handle controls which type of Sorting is prompted,

		-r : Enables Reverse Sorting
		-n : Enables Numeric Sorting

		No handle by default prompts Lexicographical Sorting.

	Concept :	At run-time, a pointer to function decides which particular
			function to be called, based on the handle provided by the user.

	Improvisation: 
			Treats a string as a group of space seperated 'fields', and sorts
			them on the basis of the field selected by the user.

			Eg: "dev 20 delhi"

				The above string has three fields: 1. Name
								2. Age
								3. Residence

			User can select the field number to be sorted and all the strings in that
			particular field would undergo sorting.


Happy Coding:) !

*/

int main(int argc, char const * argv[]) {

	char * lines[ MAXLINES ];

	int no_of_lines = 0, last_n_lines, memory_status, type, field_no, directorysort_flag;

	fetchInputLines( lines , &no_of_lines , &memory_status );

	fetchFieldNumberToSort( argc , argv , lines , &field_no );

	directorysort_flag = checkTypeOfSorting( argc , argv , &type );

	sortHandler( type , lines , no_of_lines , directorysort_flag , field_no );

	printSortedLines( lines , no_of_lines , type , directorysort_flag );

	return 0;

}