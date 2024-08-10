//Program #3: Part #1: Handling Fractions
//Santosh Ramesh   CS 161   Yipeng   11-5-19

//Code
/**********************************************************
** Program: HandlingFunctions.cpp
** Author: Santosh Ramesh
** Date: 11/5/19
** Description: This program reduces functions to the lowest possible terms, while incorporating error handling for inputs
** Inputs: There will be two inputs: a numerator value, and a denominator value. These will be initally read as strings for error handling, but later changed to integer values
** Output: A numerator and denominator integer value of a fraction in lowest terms
**********************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

// FUNCTION DECLARATIONS
/******************************************************************* 
** Function: GCF()
** Description: This function finds the greatest common factor between two numbers
** Parameters: int numerator, int denominator
** Pre-conditions: a numerator and denominator value of a fraction is taken, unreduced
** Post-conditions: the GCF value called "divider" is returned
*******************************************************************/
int GCF (int numerator, int denominator){
    int larger = 0;
    int divider = 0;
    
    // determining which number is larger
    if (abs(numerator) >= abs(denominator)){
        larger = abs(numerator);
    } else {
        larger = abs(denominator);
    }
    
    // finding the GCF of the two numbers
    for (int x = 1; x < larger; x++){
        if ((numerator % x == 0) && (denominator % x ==0)){
            divider = x;
        }
    }
    
    return divider;
}

/******************************************************************* 
** Function: to_lowest_terms()
** Description: Reduces the numerator and denominator, while error handling for a 0 denominator
** Parameters: int &numerator, int &denominator
** Pre-conditions: takes in the numerator and denominator values referenced in the main function
** Post-conditions: returns a true or false value for whether there is a 0 in the denominator or not
*******************************************************************/
bool to_lowest_terms(int &numerator, int &denominator){
    bool check = true;
    
    if (denominator == 0){
        check = false;
    } else {
        int divider = GCF(numerator, denominator);
        numerator = numerator / divider;
        denominator = denominator / divider;
    }
    
    return check;
}

/******************************************************************* 
** Function: error_handling()
** Description: This function checks each character of the numerator and denominator inputs, and makes sure they are integers
** Parameters: string value
** Pre-conditions: An unchanged string is taken in, representing either the numerator or denominator input
** Post-conditions: A true or false value is returned based on whether there are non-integers present or not
*******************************************************************/
bool error_handling (string value){
    bool check = true;
    int bad_count = 0;
    int ascii = value[0];
    
    // checks if the first character is either not an integer or not a negative sign
    if (!(ascii >= 48 && ascii <= 57) && !(ascii == 45)){
			bad_count++;
		} 
    
    // checks the rest of the characters for non-integer values
    for (int i = 1; i < value.length(); i++){
        ascii = value[i];
        if (!(ascii >= 48 && ascii <= 57)){
			bad_count++;
		}
    }
    
    if (bad_count > 0){
        check = false;
    }
    
    return check;
}

int main()
{
    /* Justification  for why int main is larger than 15 lines of code: Much of the code has gone 
    to error handling the numerator and denominator, which is why it is so long. */
    
    bool repeat_fraction = true;
    // main while loop to repeat the function
    while (repeat_fraction){
        int another = 0;
        bool again = true;
        string numerator_input = "";
        string denominator_input = "";
        
        cout << "Welcome to the fraction reducer" << endl;
        
        // while loop used to error handle the numerator values
        while (again){
            cout << "Enter in a numerator value" << endl;
            cin >> numerator_input;
            
            if (error_handling(numerator_input) == false){
                cout << "Error, your numerator input is invalid" << endl;
                again = true;
            } else {
                again = false;
            }
        }
        again = true;
        
        // while loop used to error handle the denominator values
        while (again){
            cout << "Enter in a denominator value" << endl;
            cin >> denominator_input;
            
            if (error_handling(denominator_input) == false){
                cout << "Error, your denominator input is invalid" << endl;
                again = true;
            } else {
                again = false;
            }
        }
        again = true;
        
        int numerator = atoi(numerator_input.c_str());
        int denominator = atoi(denominator_input.c_str());
        
        // printing the reduced fraction
        if (to_lowest_terms(numerator, denominator) == false){
            cout << "The denominator is 0, therefore it is impossible to simplify" << endl;
            cout << "Restart the program to try again" << endl;
        } else {
            cout << "The numerator is " << numerator << endl;
            cout << "The denominator is " << denominator << endl;
            cout << "" << endl;
        }
        
        // determining if the user would like to try again
        cout << "Would you like to reduce another fraction? (0 is yes, 1 is no)" << endl;
        cin >> another;
        
        if (another == 0){
            repeat_fraction = true;
        } else if (another == 1){
            repeat_fraction = false;
        }
    }

    return 0;
}




