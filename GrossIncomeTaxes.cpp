
/**********************************************************
** Program: GrossIncomeTaxes.cpp
** Author: Santosh Ramesh
** Description: This program calculates the gross income and taxes of a car salesperson
** Inputs: monthly salary (MS), months worked (MW), cost of cars (COC), cars sold (CS), misconducts observed (MO), tax year (TY), state (S)
** Output: gross income (GI), taxes (T), remaining income (RI)
**********************************************************/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main (){

cout <<"Welcome to the gross income and taxes calculator for a salesperson. Please input the following values to generate the gross income, taxes that need to be paid, and the remaining income after taxes." << endl <<endl;
	

	// INITIALIZING INPUT VARIABLES
	double MS = 0.00;
	double COC = 0.00;
	int MW = 0;
	int CS = 0;
	int MO = 0;
	int TY = 0;
	char S = '0';


	// ASKING USERS FOR INPUTS
	// monthly salary (MS)
	cout << "1. Please input the base monthly salary for the car salesperson:" << endl;
	cin >> MS;
	cout << endl;

	// months worked (MW)
	cout << "2. Please enter the number of months worked by the car salesperson?" << endl;
	cin >> MW;
	cout << endl;

	// cost of car (COC)
	cout << "3. Enter the price of the car (not the value it was sold at):" << endl;
	cin >> COC;
	cout << endl;

	// cars sold (CS)
	cout << "4. Please enter the number of cars sold?" << endl;
	cin >> CS;
	cout << endl;

	// misconducts observed (MO)
	cout << "5. How many misconducts were observed by the car salesperson?" << endl;
	cin >> MO;
	cout << endl;

	// tax year (TY)
	cout << "6. What is the current tax year for the car salesperson?" << endl;
	cin >> TY;
	cout << endl;

	// state (S)
	cout << "7. What state does the car salesperson reside in?" << endl;
	cin >> S;
	cout << endl << endl;


	// INITIALIZING VARIABLES FOR CALCULATIONS
	double AS = 0;
	int PG = 0;
	double ACSP = 0;
	double P = 0;
	double D = 0;
	double GI = 0;
	

	// CALCULATIONS FOR GROSS INCOME
	// annual salary (AS)
	AS = MS * MW;
	
	// average car selling price (ACSP)
		// calculating percentage (PG)
		srand(time(NULL)); // seeds random number generator
		PG = rand() % 6 + 5;

	ACSP = ((PG / 100) + 1) * COC;

	// profits (P)
	P = CS * (ACSP - COC);
	
	// deductions (D)
	if (MO == 0) {
		D = 0;
	} else {
		D = 100 * pow (2, MO);
	}

	// gross income (GI)
	GI = AS + (0.02 * P) - D;


	// CALCULATIONS FOR TAXES
	double T = 0;

	// determining tax year
	if (TY == 2017){
		// determining state of residence
		if (S == 'A'){
			// determining taxes (T)
			T = .06 * GI;
		}

		// determining state of residence
		else if (S == 'B'){
			// determining taxes (T)
			if (GI < 2000) {
				T = 0;
			} else if (GI >= 2000 && GI < 10000) {
				T = 100;
			} else {
				T = (.10 * GI) + 100;
			}
		}

		// determining state of residence
		else{
			// determining taxes (T)
			if  (GI < 3500) {
				T = .05 * GI;
			} else if (GI >= 3500 && GI < 9000) {
				T = .07 * GI + 175;
			} else if (GI >= 9000 && GI < 125000) {
				T = (.09 * GI) + 560;
			} else {
				T = (.099 * GI) + 11000;
			}
		}
	}


	// determining tax year
	if (TY == 2018){
		// determining state of residence
		if (S == 'A'){
			// determining taxes (T)
			T = .08 * GI;
		}

		// determining state of residence
		else if (S == 'B'){
			// determining taxes (T)
			if (GI < 2000) {
				T = 0;
			} else if (GI >= 2000 && GI < 10000) {
				T = 115;
			} else {
				T = (.105 * GI) + 115;
			}
		}

		// determining state of residence
		else{
			// determining taxes (T)
			if  (GI < 3450) {
				T = .05 * GI;
			} else if (GI >= 3450 && GI < 8700) {
				T = .07 * GI + 172.5;
			} else if (GI >= 8700 && GI < 125000) {
				T = (.09 * GI) + 540;
			} else {
				T = (.099 * GI) + 11007;
			}
		}
	}

	
	// CALCULATIONS FOR REMAINING INCOME
	double RI = 0;

	// remaining income (RI)
	RI = GI - T;

	
	// PRINTING VALUES
	cout << "The gross income (without taxes): $" << GI << endl;
	cout << "The total taxes that need to be paid: $" << T << endl;
	cout << "The remaining income is: $" << RI << endl;

	return 0;
}



