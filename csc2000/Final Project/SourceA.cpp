// SourceA.cpp : Fraction Calculator
//

#include<iostream>
using namespace std;

// Supporting functions

//menu function
int mainOptionWindow() {
	cout << "Welcome to the fraction calculator!\n"
		<< "This application will present a menu and allow you to select from a range of different options to manipulate fractions \n"
		<< "You, the user will be able to take the following actions : \n"
		<< "Add \t Subtract \t Multiply \t Divide \n"
		<< "Please choose from one of the options below: \n"
		<< "1: Add two fractions \n"
		<< "2: Subtract two fractions \n"
		<< "3: Multiply two fractions \n"
		<< "4: Divide two fractions \n \n"
		<< "0: To terminate the program and exit \n\n"
		<< "What is your selection?\t";
	int userChoice;
	cin >> userChoice;
	return userChoice;	 
}

// addition of fractions passed in as parameters
void addFractions(int frac1Numerator, int frac1Denominator, int frac2Numerator, int frac2Denominator, int &resultNumerator, int &resultDenominator) {
	resultNumerator = (frac1Numerator * frac2Denominator) + (frac1Denominator * frac2Numerator);
	resultDenominator = (frac1Denominator) * (frac2Denominator);

	cout << "\nThe summation is : " << frac1Numerator << "/" << frac1Denominator << " + " << frac2Numerator << "/"<< frac2Denominator << " = " << resultNumerator <<  "/" << resultDenominator << endl << endl;
	cout << "Returning to main menu ... \n";
}

// subtract of fractions that are passed in as parameters
void subtractFractions(int frac1Numerator, int frac1Denominator, int frac2Numerator, int frac2Denominator, int &resultNumerator, int &resultDenominator) {
	resultNumerator = (frac1Numerator * frac2Denominator) - (frac1Denominator * frac2Numerator);
	resultDenominator = (frac1Denominator)*(frac2Denominator);

	cout << "\nThe difference is : " << frac1Numerator << "/" << frac1Denominator << " - " << frac2Numerator << "/" << frac2Denominator << " = " << resultNumerator << "/" << resultDenominator << endl << endl;
	cout << "Returning to main menu ... \n";
}

// multiplication of fractions that are passed in as parameters
void multiplyFractions(int frac1Numerator, int frac1Denominator, int frac2Numerator, int frac2Denominator, int &resultNumerator, int &resultDenominator) {
	resultNumerator = (frac1Numerator * frac2Numerator);
	resultDenominator = (frac1Denominator * frac2Denominator);

	cout << "\nThe product is : " << frac1Numerator << "/" << frac1Denominator << " * " << frac2Numerator << "/" << frac2Denominator << " = " << resultNumerator << "/" << resultDenominator << endl << endl;
	cout << "Returning to main menu ... \n";
}

// division of fractions that are passed in as parameters
void divideFractions(int frac1Numerator, int frac1Denominator, int frac2Numerator, int frac2Denominator, int &resultNumerator, int &resultDenominator) {
	resultNumerator = (frac1Numerator * frac2Denominator);
	resultDenominator = (frac1Denominator * frac2Numerator);

	cout << "\nThe quotient is : " << frac1Numerator << "/" << frac1Denominator << " / " << frac2Numerator << "/" << frac2Denominator << " = " << resultNumerator << "/" << resultDenominator << endl << endl;
	cout << "Returning to main menu ... \n";
}


// Main function
int main()
{
	// implement supporting functions
	int menuSelection = 12;
	int frac1Numerator, frac1Denominator, frac2Numerator, frac2Denominator, resultNumerator = 0, resultDenominator = 0;
	while (menuSelection != 0) {
		menuSelection = mainOptionWindow();
		switch (menuSelection) {
		case 1:
			cout << "Additon function executing ...\n";
			cout << "Please enter the data for fraction 1 \n"
				<< "Enter a numerator: ";
			cin >> frac1Numerator;
			cout << "Enter a denominator: ";
			cin >> frac1Denominator;
			cout << "Please enter the data for fraction 2 \n"
				<< "Enter a numerator: ";
			cin >> frac2Numerator;
			cout << "Enter a denominator: ";
			cin >> frac2Denominator;
			addFractions(frac1Numerator, frac1Denominator, frac2Numerator, frac2Denominator, resultNumerator, resultDenominator);
			break;

		case 2:
			cout << "Subtraction function executing ... \n";
			cout << "Please enter the data for fraction 1 \n"
				<< "Enter a numerator: ";
			cin >> frac1Numerator;
			cout << "Enter a denominator: ";
			cin >> frac1Denominator;
			cout << "Please enter the data for fraction 2 \n"
				<< "Enter a numerator: ";
			cin >> frac2Numerator;
			cout << "Enter a denominator: ";
			cin >> frac2Denominator;
			subtractFractions(frac1Numerator, frac1Denominator, frac2Numerator, frac2Denominator, resultNumerator, resultDenominator);
			break;

		case 3:
			cout << "Multiplication function executing ... \n";
			cout << "Please enter the data for fraction 1 \n"
				<< "Enter a numerator: ";
			cin >> frac1Numerator;
			cout << "Enter a denominator: ";
			cin >> frac1Denominator;
			cout << "Please enter the data for fraction 2 \n"
				<< "Enter a numerator: ";
			cin >> frac2Numerator;
			cout << "Enter a denominator: ";
			cin >> frac2Denominator;
			multiplyFractions(frac1Numerator, frac1Denominator, frac2Numerator, frac2Denominator, resultNumerator, resultDenominator);
			break;

		case 4:
			cout << "Division function executing ... \n";
			cout << "Please enter the data for fraction 1 \n"
				<< "Enter a numerator: ";
			cin >> frac1Numerator;
			cout << "Enter a denominator: ";
			cin >> frac1Denominator;
			cout << "Please enter the data for fraction 2 \n"
				<< "Enter a numerator: ";
			cin >> frac2Numerator;
			cout << "Enter a denominator: ";
			cin >> frac2Denominator;
			divideFractions(frac1Numerator, frac1Denominator, frac2Numerator, frac2Denominator, resultNumerator, resultDenominator);
			break;

		case 0:
			cout << "Program terminated ... \n";
			break;
			
		default:
			cout << "INVALID INPUT, please enter a number 1-4, menu restarting ... \n";
		}
	}
    return 0;
}

