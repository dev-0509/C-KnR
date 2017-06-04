#include "stdio.h"
#include "stdlib.h"
#include "Global.h"

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
	
	int choice;

	system( "clear" );

	choice = displayMenu();

	stringHandler( choice );

	return 0;

}