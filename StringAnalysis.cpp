//Program #4: String Analysis
//Santosh Ramesh   CS 161   Yipeng   11-21-19

//Code
/**********************************************************
** Program: StringAnalysis.cpp
** Author: Santosh Ramesh
** Date: 11-21-19
** Description: Analyzes a string for Palindromes, the Frequency of Words, and the Frequency of Inputed Words
** Inputs: string input, int method, int words, string repeat
** Output: This varies based on method: (1) a yes or no, (2) each word in the string and the frequency of the words, (3) the frequency of words that are inputed
**********************************************************/

#include <iostream>
#include <cstring>
#include<cstdlib>
#include<string>

using namespace std;

// FUNCTION DECLARATIONS
/******************************************************************* 
** Function: string_input
** Description: This function takes in an input from the user to represent the string that will be used for the rest of the methods
** Parameters: char* u_input, char *method
** Pre-conditions: It takes in an empty string representing the input, and an empty string representing the method to be used
** Post-conditions: It returns a string filled with the user's input, and a method choice to be used for string analysis
*******************************************************************/
void string_input(char* u_input, char *method){
	cout << "Enter a string to be analyzed" << endl;
	cin.getline (u_input, 1025);
    
	bool check = true;
	while (check){
		char m1[1025] = {'1'};
		char m2[1025] = {'2'};
		char m3[1025] = {'3'};

		cout << "Enter in a method to choose from" << endl;
		cin >> method;
		if (strcmp(method, m1) == 0 || strcmp(method, m2) == 0 || strcmp(method, m3) == 0){
    			check = false;
		} else {
			cout << "Error, input a number between 1 and 3" << endl;
		}
	}
}

/******************************************************************* 
** Function: palindrome_purge
** Description: Removes all spacing, special characters, and makes upper-case letters lowercase (keeps letters & numbers)
** Parameters: char *u_input
** Pre-conditions: Takes in an unchanged user-input string
** Post-conditions: Modifies the string to exclude special characters as per the description
*******************************************************************/
void palindrome_purge(char *u_input){
	char temporary [1025] = {'0'};
	int j = 0;
	for (int i = 0; i < strlen(u_input); i++){
		if ((u_input[i] >= 65 & u_input[i] <= 90) || (u_input[i] >= 97 & u_input[i] <= 122) || (u_input[i] >= 48 & u_input[i] <= 57)){
			if ((u_input[i] >= 65 & u_input[i] <= 90)){
				temporary[j] = u_input[i] + 32;
				j++;
			} else {
				temporary[j] = u_input[i];
				j++;
			}
		}
	}
	
	strcpy(u_input, temporary);
}

/******************************************************************* 
** Function: is_palindrome
** Description: Determines whether or not the user-input is a palindrome or not
** Parameters: char *u_input
** Pre-conditions: Takes in a user-inputted string
** Post-conditions: Returns a true or false value based on whether or not the input is a palindrome or not
*******************************************************************/
bool is_palindrome (char *u_input){
	int size = 0;
	size =  strlen(u_input);
	char* original = new char[size];
	char* flipped = new char[size];	
	
	for (int i = 0; i < size; i++){
		original[i] = u_input[i];
	}
	cout << original << endl;

	int subtract = size - 1;
	for (int i = 0; i < size; i++){
		flipped[i] = u_input[subtract];
		subtract--;
	}
	cout << flipped << endl;

	if (strcmp(flipped, original) == 0){
		delete[] original;
		delete[] flipped;
		return true;
	} else{
		delete[] original;
		delete[] flipped;		
		return false;
	}
}

/******************************************************************* 
** Function: frequency_purge
** Description: Removes all of the numbers, special characters, and converts the upper case letters into lower-case ones (keeps letters and spacing)
** Parameters: char *u_input
** Pre-conditions: Takes in the user-inputted string unmodified
** Post-conditions: modifies the inputted string based on the description aforementioned
*******************************************************************/
void frequency_purge(char *u_input){
	char temporary [1025] = {'0'};
	int j = 0;
	for (int i = 0; i < strlen(u_input); i++){
		if ((u_input[i] >= 65 & u_input[i] <= 90) || (u_input[i] >= 97 & u_input[i] <= 122) || u_input[i] == 32){
			if ((u_input[i] >= 65 & u_input[i] <= 90)){
				temporary[j] = u_input[i] + 32;
				j++;
			} else {
				temporary[j] = u_input[i];
				j++;
			}
		}
	}
	
	strcpy(u_input, temporary);
}

/******************************************************************* 
** Function: word_split
** Description: Splits each of the words in the user's input and places them into separate array indexes (split based on spacing)
** Parameters: char *u_input, string *words, int &next_word
** Pre-conditions: Takes in the user string, the empty words array to be filled with all of the words used, and the "next-word" variable which helps keep track of how long the words array is
** Post-conditions: Returns the words array filled with the words used in the string input
*******************************************************************/
void word_split (char *u_input, string *words, int &next_word){
	int j = 0;
	string current = "";

	for (int i = 0; i < strlen(u_input); i++){
		if  (u_input[i] != 32){
			current = current + u_input[i];
		 if ((u_input[i + 1]) == 32 || (u_input[i + 1]) == 0){
			words[next_word] = current;
			next_word++;
			current = "";
			}
		}
	}
}

/******************************************************************* 
** Function: frequency_check
** Description: Determines how often each word occurs in the inputed string
** Parameters: char* u_input, string* words
** Pre-conditions: Takes in the string input along with the words array which contains all of the words used in the string input
** Post-conditions: Prints out the number of times each word occurs in the string
*******************************************************************/
void frequency_check (char* u_input, string* words){
	int frequency = 1;
	for (int i = 0; i < 256; i++){
		if (words[i] != ""){
			for (int j = (i+1); j < 256; j++){
				if (words[i] == words[j]){
				frequency++;
				words[j] = "";
				}
			}
			cout << words[i] << " has appeared this many times: " << frequency << endl;
			frequency = 1;
		}
	}
}

/******************************************************************* 
** Function: input_amount
** Description: Determines the number of words the user would like to search the string for in method 3
** Parameters: int &inputs
** Pre-conditions: Takes in a value for inputs that will be changed based on the number of words the user wants to search for
** Post-conditions: Returns the exact value for the number of words to be searched for
*******************************************************************/
void input_amount(int &inputs){
	string word_amount_input;
	bool check = true;
	int bad = 0;
	cin.ignore();

	while (check) {
		cout << "How many words would you like to input?" << endl;
		cin >> word_amount_input;
		for (int i = 0; i < word_amount_input.length(); i++){
			char temp = word_amount_input[i];
			if (temp < 48 ||  temp > 57 || temp  == 0){
				bad++;
			}
		}

		if (bad > 0){
			cout << "You have inputed a non-integer value, please try again" << endl;
			bad = 0;
		} else{
			check = false;
		}
	}
	inputs = atoi (word_amount_input.c_str());
}

/******************************************************************* 
** Function: word_input
** Description: Asks the user to input the words to search the original string for
** Parameters: string* input_words, int inputs
** Pre-conditions: Takes in the empty array of input_words, along with the length of the array (which is "inputs")
** Post-conditions: Fills the array with the words that will be searched in the string
*******************************************************************/
void word_input (string* input_words, int inputs){
	int j = 1;
	for (int i = 0; i < inputs; i++){
		string temporary = "";
		cout << "Enter in word number " << j << ": ";
		cin.ignore();
		cin >> temporary;
		
		input_words[i] = temporary;
		temporary = "";
		j++;
	}
}

/******************************************************************* 
** Function: array_compare
** Description: Compares the array of words created from the word_split function and the inputed list of words
** Parameters: string* words, string* input_words, int inputs, int next_word
** Pre-conditions: It takes in the two arrays of words to compare, along with the length of each array
** Post-conditions: Determines the frequency of every user-inputted word in the string-input
*******************************************************************/
void array_compare (string* words, string* input_words, int inputs, int next_word){
	int count = 0;

	for (int i = 0; i < inputs; i++){
		for (int j = 0; j < next_word; j++){
			if (input_words[i] == words[j]){
				count++;
			}
		}
		cout << input_words[i] << " has appeared this many times: " << count << endl;
	count = 0;
	}
}

/******************************************************************* 
** Function: repeat()
** Description: Determines whether or not the user wants to repeat the program
** Parameters: none
** Pre-conditions: Asks the user wants to repeat the program
** Post-conditions: Returns a true/false value determined based on the user response
*******************************************************************/
bool repeat(){
	bool check = true;
	while (check){
		string repeat = "";
		cout << "Would you like to analyze another string? Input a yes or no answer" << endl;
		cin >> repeat;
		if (repeat == "yes"){
			return true;
			check = false;
		} else if (repeat == "no"){
			return false;
			check = false;
		} else{
			cout << "Error, input invalid, please try again" << endl;
			check = true;
		}
	}
}

// MAIN FUNCTION
int main() {
	// JUSTIFICATION FOR INT MAIN LENGTH:
	// int main is more than 15 lines long because it contains many of the function calls; I could have called for the functions within other functions, but for the sake of clarity
	// I wanted to keep all of the calls in the main for debugging purposes
	bool check = true;
	while (check){
	int next_word = 0;
	int inputs = 0;
 	char method[1025] = {'0'};
	char* u_input = new char[0];
	string words [256];
	string_input(u_input, method);
		
	int chosen = atoi (method);
	if (chosen == 1){
		palindrome_purge(u_input);
		if (is_palindrome(u_input) == true){
			cout << "The string is a palindrome" << endl;
		} else {
			cout << "The string is not a palindrome" << endl;
		}
	} else if (chosen == 2){
		frequency_purge(u_input);
		cout << u_input << endl;
			
		word_split(u_input, words, next_word);
		frequency_check(u_input, words);		
	} else{
		input_amount(inputs);
		string* input_words = new string[inputs];
		word_input(input_words, inputs);
		word_split(u_input, words, next_word);
		array_compare(words, input_words, inputs, next_word);
		delete[] input_words;
	}

	delete[] u_input;
	check = repeat();
	cin.ignore();

	}
 	return 0;
}





