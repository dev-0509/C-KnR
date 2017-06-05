#include "stdio.h"
#include "string.h"
#include "Global.h"
#include "StringHandler.h"

int compareEachCharacter(char * comparable_string, char * comparator_string, int no_of_chars) {

	int char_count = 0;

	while( char_count != no_of_chars ) {

		++char_count;

		if( *comparable_string++ == *comparator_string++ )

			continue;

		else

			return NOT_EQUAL;

	}

	return EQUAL_STRINGS;

}

int checkLengthOfComparatorString(char * comparable_string, int no_of_chars) {

	if( strlen( comparable_string ) < no_of_chars )

		return GREATER;

	return EQUAL_LENGTH;

}

int compareStrings(char * comparable_string, char * comparator_string, int no_of_chars) {

	int status;

	status = checkLengthOfComparatorString( comparable_string , no_of_chars );

	if( status == EQUAL_LENGTH )

		status = compareEachCharacter( comparable_string , comparator_string , no_of_chars );

	else

		return status;

	if( status == EQUAL_STRINGS )

		return EQUAL_STRINGS;

	else

		return NOT_EQUAL;

}