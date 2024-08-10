//Program #3: Part #2: Fractals
//Santosh Ramesh   CS 161   Yipeng   11-5-19

//Code
/**********************************************************
** Program: Fractals.cpp
** Author: Santosh Ramesh
** Date: 11/5/19
** Description: This program uses recursion to create fractal images moved over specific column lengths
** Inputs: The size of the fractal and the number of columns shifted left (both will be hard coded)
** Output: A fractal image created based on the hard-coded specifications
**********************************************************/

#include <iostream>

using namespace std;

// FUNCTION DECLARATIONS
/******************************************************************* 
** Function: recursion()
** Description: Creates a line of asterisks with the given parameters
** Parameters: int size, int space
** Pre-conditions: takes the size (number of asterisks) and the space (the # of columns shifted)
** Post-conditions: prints a row of asterisks
*******************************************************************/
void recursion(int size, int space){
    // creates the spacing
    int s = space - size;
    for (int i = 0; i < s; i++){
        cout <<" ";
    }
    // creates the stars
    for (int i = 0; i < size; i++){
        cout <<"* " ;
    }
    cout<< endl;
}

/******************************************************************* 
** Function: pattern()
** Description: Uses recursion to create multiple lines of asterisks to create the fractal pattern
** Parameters: int size, int space
** Pre-conditions: takes in the size of the fractal and the number of columns for the shift
** Post-conditions: prints the entire fractal
*******************************************************************/
void pattern(int size, int space){
    // creating the recursive pattern
    if (size > 0){
        pattern(size - 2, space);
        recursion(size, space);
        pattern(size - 2, space);
    }
}

int main(){
    // declaring the inputs
    int size_of_fractal = 5;
    int columns = 10;
    
    // function call
    cout << "Creating a fractal of size " << size_of_fractal << " and " << columns << " columns:" << endl;
    pattern(size_of_fractal, size_of_fractal + columns);

    return 0;
}








