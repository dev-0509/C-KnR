#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "Global.h"
#include "StringHandler.h"

void displayResult(int status, char * string, int choice) {

	switch( choice ) {

		case 1:	printf("\n\nMain String after Copy Manipulation: %s\n\n", string);
				
			break;

		case 2:	if( status == EQUAL_STRINGS )

				printf("\n\nBoth Strings are Equal!\n\n");

			else

				printf("\n\nString Comparison not possible!\n\n", status);

			break;

		case 3:	if( status == SUCCESS )

				printf("\n\nConcatenated String: %s\n\n", string);

			else

				printf("\n\nString Concatenation not possible!\n\n");

			break;

	}

}

void fetchInput(char * main_string, char * target_string, int * no_of_chars) {

	system( "clear" );

	printf("\n\tInput main string: ");	
	scanf( "%s" , main_string );

	printf("\n\tInput target string: ");	
	scanf( "%s" , target_string );

	printf("\n\tInput number of characters to be operated: ");	
	scanf( "%d" , no_of_chars );

	if( *no_of_chars > strlen( target_string ) )

		printf("Hey! Number of characters exceed the length of Target String!\n");

}

int stringHandler(char * output_string, int choice) {

	char main_string[ MAXLENGTH ], target_string[ MAXLENGTH ];
	int no_of_chars, status;

	fetchInput( main_string , target_string , &no_of_chars );

	switch( choice ) {

		case 1:	status = copyStrings( main_string , target_string , no_of_chars );

			strcpy( output_string , main_string );

			return status;

		case 2:	status = compareStrings( main_string , target_string , no_of_chars );

			return status;

		case 3:	status = concatStrings( main_string , target_string , no_of_chars );

			strcpy( output_string , main_string );

			return status;

		default: printf("\nInvalid Input!");

	}

}

int displayMenu() {

	int choice;

	printf("\t------------------------------------------------------\n");
	printf("\t\t1. Copy String upto 'n' characters\n");
	printf("\t\t2. Compare Strings upto 'n' characters\n");
	printf("\t\t3. Concatenate String upto 'n' characters\n");
	printf("\t------------------------------------------------------\n\n");

	printf("Type of String Manipulation? : ");
	scanf( "%d", &choice );

	return choice;

}

int main(int argc, char const *argv[]) {
	
	char output_string[ MAXLENGTH ];
	int choice, status;

	system( "clear" );

	choice = displayMenu();

	status = stringHandler( output_string , choice );

	displayResult( status , output_string , choice );

	return 0;

}