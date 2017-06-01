# Shell Script for Executing Test Cases

function startScript() {

	executeTests 

	read

}

function checkIfEqual() {

	if [ $1 == $2 ]
	then 
		echo "Pass"
	else
		echo "Fail"
	fi

}

function printTestCaseResult() {

	echo "Test $1 : $2"

}

function callExecutable() {

	output_string=$( ./5.2_Executable $string )

	echo $output_string

}

function executeTests() {

	testnumber=1

	# Compile and Create Executable
	gcc 5.2__getFloat.c -o 5.2_Executable

  #-------------------------- TEST CASE 1 ----------------------------------#
	string="+1234.5678"

	expected=1234.567800

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 2 ----------------------------------#
	string="-98124.12"

	expected=-98124.120000

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 3 ----------------------------------#
	string="345.12002"

	expected=345.120020

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 4 ----------------------------------#
	string="-4.289"

	expected=-4.289000

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
    ((testnumber++))


  #-------------------------- TEST CASE 5 ----------------------------------#
	string="+abs.12"

	expected="Invalid!"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
	((testnumber++))


  #-------------------------- TEST CASE 6 ----------------------------------#
	string="-5498"

	expected=-5498.000000

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  
}

startScript