/*	Program Info:
*	There is a much easier way to write this program.
*	This is just a basic calculator program that I am writing to help me remember what I learned years ago in class
* 	Eventually, have user enter numbers as a line, then read the line and process based off of operators PEMDAS
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
* PROTOTYPES
*/
void addition();
void subtraction();
void multiplication();
void division();

//Validation Prototypes
int validate_intRange(int userInput, int range_min, int range_max);
double validate_double(double userInput);


/********************************************************************************************************************
*																													*
*														MAIN														*
*																													*
********************************************************************************************************************/
void main()
{
	//Variables
	bool endProgram = false;
	//MENU
	do
	{
		int userInput_menu;	//holds user input for selecting from menu options.
		cout << std::string(100, '-') << endl;	//string(#,C) C is outputted # amount of times.
		cout << "SELECT A FUNCTION FROM BELOW:" << endl
			<< "1. Addition" << endl
			<< "2. Subtraction" << endl
			<< "3. Multiplication" << endl
			<< "4. Division" << endl
			<< "5. Exit Program" << endl;
		cout << std::string(100, '-') << endl;
		//Get user input
		cout << "SELECTION: ";
		cin >> userInput_menu;
		//INPUT VALIDATION - user input with a range between 0 and 5
		userInput_menu = validate_intRange(userInput_menu, 0, 5);
		//
		cout << "User selected: " << userInput_menu << endl;

		//Switch statement for menu
		switch (userInput_menu)
		{
		case 1:
			cout << "\nAddition chosen.\n";
			addition();
			break;
		case 2:
			cout << "\nSubtraction chosen.\n";
			subtraction();
			break;
		case 3:
			cout << "\nMultiplication chosen.\n";
			multiplication();
			break;
		case 4:
			cout << "\nDivision chosen.\n";
			division();
			break;
		case 5:
			cout << "\nEnding program.\n";
			endProgram = true;
		};
	}
	while (endProgram != true);
	



	//End of program
	return;
};

void addition()
{
	//Variables
	double varA;
	double varB;
	double solve = 0;	//Holds the solution.

	//Get user input - addition
	cout << "Enter the first number: ";
	cin >> varA;
	//Input validation
	varA = validate_double(varA);
	cout << "Enter the second number: ";
	cin >> varB;
	//Input validation
	varB = validate_double(varB);

	//Add varA and varB together and assign as new value of solve.
	solve = varA + varB;
	//Output the answer.
	cout << varA << " + " << varB << " = " << solve << endl;

	//End of function
	return;
};
void subtraction()
{
	//variables
	double varA;	//Number subtracted from
	double varB;	//Subtracting number
	double solve;	//Holds solution

	//Get user input - subtraction
	cout << "Enter the first number: ";
	cin >> varA;
	varA = validate_double(varA);	//Input validation
	cout << "Enter the second number: ";
	cin >> varB;
	varB = validate_double(varB);	//Input validation

	//calculate result
	solve = varA - varB;

	//Print result
	cout << varA << " - " << varB << " = " << solve << endl;

	//End of function
	return;
};
void multiplication()
{
	//Variables
	double varA;
	double varB;
	double solve;

	//Get input
	cout << "Enter the first number: ";
	cin >> varA;
	varA = validate_double(varA);	//input validation
	cout << "Enter the second number: ";
	cin >> varB;
	varB = validate_double(varB);	//input validation
	
	//calculate
	solve = varA * varB;

	//output
	cout << varA << " * " << varB << " = " << solve << endl;
	
	//End of function
	return;
};
void division()
{
	//variables
	double varA;
	double varB;
	double solve;

	//Get input
	cout << "Enter the first number: ";
	cin >> varA;
	varA = validate_double(varA);	// input validation
	cout << "Enter the second number: ";
	cin >> varB;
	varB = validate_double(varB);	// input validation

	//calculate
	solve = varA / varB;

	//output
	cout << varA << " / " << varB << " = " << solve;

	//End of function
	return;
};

//Input validation
int validate_intRange(int userInput, int range_min, int range_max)
{
	while (cin.fail() || userInput < range_min || userInput > range_max)
	{
		//Clear the error and ignore the input.
		cin.clear();
		cin.ignore();
		//Prompt user to input a valid number
		cout << "The number you entered is an invalid option. Reenter your selection : ";
		cin >> userInput;
	};
	//Return the corrected input
	return userInput;
};

double validate_double(double userInput)
{
	while (cin.fail())
	{
		//Clear the error and ignore the input.
		cin.clear();
		cin.ignore();
		//Prompt user to input a valid number
		cout << "The number previously entered is an invalid option. Re-enter your selection: ";
		cin >> userInput;
	}
	//Return the corrected input
	return userInput;
}