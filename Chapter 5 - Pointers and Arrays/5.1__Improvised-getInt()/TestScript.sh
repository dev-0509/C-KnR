# Shell Script for Executing Test Cases

function startScript()
{
	executeTests 

	read
}

function checkIfEqual()
{
	if [ $1 == $2 ]
	then 
		echo "Pass"
	else
		echo "Fail"
	fi
}

function printTestCaseResult()
{
	echo "Test $1 : $2"
}

function callExecutable()
{
	output_string=$( ./5.1_Executable $string )

	echo $output_string
}

function executeTests()
{
	testnumber=1

	# Compile and Create Executable
	gcc 5.1__getInt.c -o 5.1_Executable

  #-------------------------- TEST CASE 1 ----------------------------------#
	string="+12345"

	expected=12345

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 2 ----------------------------------#
	string="-9812"

	expected=-9812

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 3 ----------------------------------#
	string="+abc12"

	expected="Invalid"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 4 ----------------------------------#
	string="+opa1234"

	expected="Invalid"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
    ((testnumber++))

  #-------------------------- TEST CASE 4 ----------------------------------#
	string="2401"

	expected=2401

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
}

startScript