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
	output_string=$( ./4.13_Executable $string )

	echo $output_string
}

function executeTests()
{
	testnumber=1

	# Compile and Create Executable
	gcc 4.13__reverse.c -o 4.13_Executable

  #-------------------------- TEST CASE 1 ----------------------------------#
	string="string"

	expected="gnirts"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 2 ----------------------------------#
	string="hey"

	expected="yeh"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 3 ----------------------------------#
	string="indonesia"

	expected="aisenodni"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
  	((testnumber++))


  #-------------------------- TEST CASE 4 ----------------------------------#
	string="strategic"

	expected="cigetarts"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
    ((testnumber++))

  #-------------------------- TEST CASE 4 ----------------------------------#
	string="tony"

	expected="ynot"

	output=$( callExecutable )
	result=$( checkIfEqual $expected $output )

	printTestCaseResult $testnumber $result
  #-------------------------------------------------------------------------#
}

startScript