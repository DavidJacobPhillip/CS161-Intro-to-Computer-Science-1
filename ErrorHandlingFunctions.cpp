/**********************************************************
** Program: ErrorHandlingFunctions.cpp
** Author: Santosh Ramesh
** Date: 10/26/19
** Description: This program uses functions with some error handling to output various values
** Inputs: vary based on function being used and its respective parameters (the inputs will be hardcoded with the exception of get int, which will prompt for an integer value)
** Output: Like with the "input" section, the outputs will vary based on the function being called upon; however, they all fall under the categories of boolean, int, and strings
**********************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// FUNCTION DECLARATIONS
/******************************************************************* 
** Function: check_range()
** Description: Check if an inputed value is within a provided number range
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-conditions: takes an upper and lower bound range values, along with a test number
** Post-conditions: returns a true/false value to determine if the number is in the range or not
*******************************************************************/
bool check_range (int lower_bound, int upper_bound, int test_value){
	bool check;
	if (test_value >= lower_bound && test_value <=  upper_bound){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: is_capital()
** Description: Indicates whether or not a given character is a capital
** Parameters: char letter
** Pre-conditions: takes in a single letter character
** Post-conditions: returns a true/false value to determine if the character is capital or not
*******************************************************************/
bool is_capital (char letter){
	bool check;
	int ascii = letter;
	if (ascii >= 65 && ascii <= 90){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: is_even()
** Description: checks if the number is even or not
** Parameters: int num
** Pre-conditions: takes in an integer number
** Post-conditions: returns a true/false value to determine if the integer is even or not
*******************************************************************/
bool is_even (int num){
	bool check;
	int mod = num % 2;
	if (mod == 0){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: is_odd()
** Description: checks if the number is odd or not
** Parameters: int num
** Pre-conditions: takes in an integer number
** Post-conditions: returns a true/false value to determine if the integer is odd or not
*******************************************************************/
bool is_odd (int num){
	bool check;
	int mod = num % 2;
	if (mod == 1){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: equality_test()
** Description: compares two integer numbers and checks if they are equal or not
** Parameters: int num1, int num2
** Pre-conditions: takes in two integer values
** Post-conditions: returns a "0", "1", or "-1" depending on if the num parameters are equal to, greater than, or less than equal to each other
*******************************************************************/
int equality_test (int num1, int num2){
	int check;
	if (num1 < num2){
		check = -1;
	} else if (num1 == num2) {
		check = 0;
	} else {
	check = 1;
}

return check;
}

/******************************************************************* 
** Function: float_is_equal()
** Description: compares two float  numbers and checks if they are equal or not to a certain precision
** Parameters: float num1, float num2, float precision
** Pre-conditions: takes in float values and a precision
** Post-conditions: returns a true/false depending on whether or not the values are equal to each other to the certain precision
*******************************************************************/
bool float_is_equal (float num1, float num2, float precision){
	bool check;
	float diff = abs (num1 - num2);
	if (precision >= diff){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: is_int()
** Description: confirms if the given string is an integer or not
** Parameters: string num
** Pre-conditions: takes in a string with various characters
** Post-conditions: returns a true/false depending on whether or not the string is an integer or not
*******************************************************************/
bool is_int (string num){
	bool check;
	int number = 0;

	for (int i=0; i < num.length(); i++){
		int ascii = num[i];
		if (!(ascii >= 48 && ascii <= 57)){
			number++;
		}
	}

	if (number > 0){
		check = false;
	}else {
		check = true;
	}

	return check;
}

/******************************************************************* 
** Function: numbers_present
** Description: Analyzes a string for numbers 
** Parameters: string sentence
** Pre-conditions: takes in a string
** Post-conditions: returns a true/false value if there are numbers in the string
*******************************************************************/
bool numbers_present (string sentence){
	bool check;
	int number = 0;

	for (int i=0; i < sentence.length(); i++){
		int ascii = sentence[i];
		if (ascii >= 48 && ascii <= 57){
			number++;
		}
	}

	if (number > 0){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: letters_present
** Description: Analyzes a string for letters 
** Parameters: string sentence
** Pre-conditions: takes in a string
** Post-conditions: returns a true/false value if there are letters in the string
*******************************************************************/
bool letters_present (string sentence){
	bool check;
	int letter = 0;

	for (int i=0; i < sentence.length(); i++){
		int ascii = sentence[i];
		if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)){
			letter++;
		}
	}

	if (letter > 0){
		check = true;
	} else {
		check = false;
	}

	return check;
}

/******************************************************************* 
** Function: containts_sub_string()
** Description: Indicates if there is a substring existing within another given string
** Parameters: string sentence, string sub_string
** Pre-conditions: takes in a sentence and a potential substring
** Post-conditions: returns a true/false value if the substring is contained within the sentence string
*******************************************************************/
bool contains_sub_string (string sentence, string sub_string){
	bool check = false;
	int num = 0;

	for (int i=0; i < sentence.length(); i++){
		if (sub_string[0] == sentence[i]){
				int current = i;
			for (int j = 0; j < sub_string.length(); j++){
				if (sub_string[j] == sentence[current]){
					num++;
				}
			current++;
			}
		if (num == sub_string.length()){
			check = true;
			break;
		}
	}
}

return check;
}

/******************************************************************* 
** Function: word_count()
** Description: Displays the number of words in the sentence
** Parameters: string sentence
** Pre-conditions: Takes in a sentence with words
** Post-conditions: returns the number of words in the sentence
*******************************************************************/
int word_count (string sentence){
	int words = 1;

	for (int i=0; i < sentence.length(); i++){
		int ascii = sentence[i];
		if (ascii == 32){
			words++;
		}
	}

	return words;
}

/******************************************************************* 
** Function: to_upper
** Description: capitalizes all the letters in a given string and leaves the other characters unchanged
** Parameters: string sentence
** Pre-conditions: takes in a sentence with characters
** Post-conditions: returns a new sentence with only upper case characters
*******************************************************************/
string to_upper (string sentence){
	string new_sentence;
	char letter;

	for (int i=0; i < sentence.length(); i++){
		int ascii = sentence[i];
		if (ascii >= 97 && ascii <= 122){
			letter = ascii - 32;
			new_sentence = new_sentence + letter;
		} else{
			letter = ascii;
			new_sentence = new_sentence + letter;
		}
	}

	return new_sentence;
}

/******************************************************************* 
** Function: to_lower
** Description: lowercases all the letters in a given string and leaves the other characters unchanged
** Parameters: string sentence
** Pre-conditions: takes in a sentence with characters
** Post-conditions: returns a new sentence with only lower case characters
*******************************************************************/
string to_lower (string sentence){
	string new_sentence;
	char letter;

	for (int i=0; i < sentence.length(); i++){
		int ascii = sentence[i];
		if (ascii >= 65 && ascii <= 90){
			letter = ascii + 32;
			new_sentence = new_sentence + letter;
		} else{
			letter = ascii;
			new_sentence = new_sentence + letter;
		}
	}

	return new_sentence;
}

/******************************************************************* 
** Function: get_int
** Description: unlike the other functions, this function prompts the user for a string input and then subsequently checks if that input is an integer or not
** Parameters: string prompt
** Pre-conditions: takes in a string prompt to see if it is an integer
** Post-conditions: returns an integer value if the string is an integer
*******************************************************************/
int get_int (string prompt){
	bool int_check = true;
	int non_int_present = 0;	
	int response = 0;

	for (int i=0; i < prompt.length(); i++){
		int ascii = prompt[i];
		if (!(ascii >= 48 && ascii <= 57)){
			non_int_present++;
		}
	}
	
	if (non_int_present > 0) {
		response = 0;
	} else{
		int length;
		length = prompt.length();

		for (int i = 0; i < length; i++){
		int value = prompt[i] - 48;
		int addition = pow (10, (length-1-i)) * value;
		response = response + addition;
	}
}

return response;
}

int main (){
// FUNCTION CALLS
	// check range
	cout << "Checking Range for the boundaries of 0 and 10" << endl;
	cout << "Is 5 in the range? (expected: 1): " << check_range (0,10, 5) << endl;
	cout << "Is 11 in the range? (expected: 0): " << check_range (0, 10, 11) << endl;
	cout << "" << endl;

	// is the letter capital
	cout << "Checking if the test letters are capital or not" << endl;
	cout << "Is 'a' capital? (expected: 0): " << is_capital('a') << endl;
	cout << "Is 'Z' capital? (expected: 1): " << is_capital('Z') << endl;
	cout << "" << endl;

	// is the number even
	cout << "Checking if an inputed number is even or not" << endl;
	cout << "Is the number 1 even? (expected: 0): " << is_even(1) << endl;
	cout << "Is the number 2 even? (expected: 1): " << is_even(2) << endl;
	cout << "" << endl;

	// is the number odd
	cout << "Checking if an inputed number is odd or not" << endl;
	cout << "Is the number 1 odd? (expected: 1):  " << is_odd(1) << endl;
	cout << "Is the number 2 odd? (expected: 0):  " << is_odd(2) << endl;
	cout << "" << endl;

	// are the integer numbers equal
	cout << "Checking if the two inputed integer values are equal or not" << endl;
	cout << "The numbers 10 & 15 (expected: -1): " << equality_test(10,15) << endl;
	cout << "The numbers 15 & 10 (expected: 1): " << equality_test(15,10) << endl;
	cout << "The numbers 10 & 10 (expected: 0): " << equality_test(10,10) << endl;
	cout << "" << endl;

	// are the real numbers equal
	cout << "Checking if the two inputed float values are equal or not with precision" << endl;
	cout << "The numbers 10.0 and 10.0 with 1 precision: (expected: 1): " << float_is_equal(10.0,10.0,1) << endl;
	cout << "The numbers 10.3 and 15.79 with 1 precision: (expected: 0): " << float_is_equal(10.3, 15.79,1) << endl;
	cout << "The numbers 5.0 and 5.5 with 0.5 precision: (expected: 1): " << float_is_equal(5.0,5.5,0.5) << endl;
	cout << "" << endl;

	// is the input a number
	cout << "Checking to see if the inputed string is an integer or not" << endl;
	cout << "The value 'fasdflkjf' (expected: 0): " << is_int("fasdflkjf") << endl;
	cout << "The value '1.344' (expected: 0): " << is_int("1.344") << endl;
	cout << "The value '5 98   087' (expected: 0): " << is_int("5 98   087") << endl;
	cout << "The value '78' (expected: 1): " << is_int("78") << endl;
	cout << "" << endl;

	// are there numbers present
	cout << "Checking to see if there are numbers present in the strings" << endl;
	cout << "The string 'fhdklasdfjf' (expected: 0): " << numbers_present("fhdklasdfjf") << endl;
	cout << "The string '129874asdf' (expected: 1): " << numbers_present("129874asdf") << endl;
	cout << "" << endl;

	// are there letters present
	cout << "Checking to see if there are letters present in the strings" << endl;
	cout << "The string '12984759834' (expected: 0): " << letters_present("12984759834") << endl;
	cout << "The string '129874asdf' (expected: 1): " << letters_present("129874asdf") << endl;
	cout << "The string '129874ASDF' (expected: 1): " << letters_present("129874ASDF") << endl;
	cout << "" << endl;

	// is there a substring
	cout << "Checking if there is a substring in a given string" << endl;
	cout << "The sentence 'The cow jumped over the moon' with the substring 'cow' (expected: 1): " << contains_sub_string ("The cow jumped over the moon", "cow") << endl;
	cout << "The sentence 'The cow jumped over the moon' with the substring 'coat' (expected: 0): " << contains_sub_string ("The cow jumped over the moon", "coat") << endl;
	cout << "" << endl;
	
	// number of words
	cout << "Checking the number of words in the given string" << endl;
	cout << "The sentence 'WhatDoesTheFoxSay' has this many words (expected: 1): " << word_count("WhatDoesTheFoxSay") << endl;
	cout << "The sentence 'What does the fox say' has this many words (expected: 5): " << word_count("what does the fox say") << endl;
	cout << "The sentence 'What does the fox say 15' has this many words (expected: 6): " << word_count("what does the fox say 15") << endl;
	cout << "" << endl;
	
	// capitalization of letters
	cout << "Capitalizing all of the letters in a given string" << endl;
	cout << "Old string: 'asflkjasdf6986fds' --> New string: " << to_upper("asflkjasdf6986fds") << endl;
	cout << "Old string: 'catsANDdogs' --> New string: " << to_upper("catsANDdogs") << endl;
	cout << "Old string: '123456780' --> New string: " << to_upper("123456780") << endl;
	cout << "" << endl;

	// lowercasing of letters
	cout << "Lowercasing  all of the letters in a given string" << endl;
	cout << "Old string: 'asflkjasdf6986fds' --> New string: " << to_lower("asflkjasdf6986fds") << endl;
	cout << "Old string: 'catsANDdogs' --> New string: " << to_lower("catsANDdogs") << endl;
	cout << "Old string: '123456780' --> New string: " << to_lower("123456780") << endl;
	cout << "" << endl;

	// is the prompted string an integer	
	cout << "Enter in a string to check if it is an integer or not" << endl;
	cout << "If the value is 0, then the integer input is invalid " << endl;
	string prompt = "";
	cin >> prompt;
	cout << "The integer value you have entered is: " << get_int (prompt) <<endl;
	cout << "" << endl;
	
	return 0;
}

