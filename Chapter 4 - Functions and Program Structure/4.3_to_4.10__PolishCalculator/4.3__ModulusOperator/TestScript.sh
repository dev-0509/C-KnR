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
	output_string=$( ./4.3_Executable $string )

	echo $output_string
}

function executeTests()
{
	testnumber=1

	# Compile and Create Executable
	gcc 4.3__ModulusOperatorFunctioning.c -o 4.3_Executable

  #-------------------------- TEST CASE 1 ----------------------------------#
	string="1 2 - 9 2 % x"

	expected=-1

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 2 ----------------------------------#
	string="1 2 - 4 5 + x"

	expected=-9

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 3 ----------------------------------#
	string="9 8 + 6 2 ~ + 2 ~"

	expected=10

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 4 ----------------------------------#
	string="9 0 ~ 2 4 +"

	expected="Error!"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
    ((testnumber++))

  #-------------------------- TEST CASE 4 ----------------------------------#
	string="9 3 ~ 2 0 %"

	expected="Error!"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
}

startScript