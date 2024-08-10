//Program #5: Connect Four
//Santosh Ramesh   CS 161   Yipeng   12-2-19

//Code
/**********************************************************
** Program: ConnectFour.cpp
** Author: Santosh Ramesh
** Date: 12-6-19
** Description: This program is designed to allow the user to play a game of connect four on any size board they desire
** Inputs: the size of the board, the number of players, if they would like to go first (1-player), and if they would like to play again
** Output: The game board, with a winner / tie declaration at the end of each game
**********************************************************/

#include <iostream>
#include <cstring>
#include<cstdlib>
#include<string>
#include<ctime>

using namespace std;

// FUNCTION DECLARATIONS
/******************************************************************* 
** Function: initializer()
** Description: This function checks if the input entered in by the user is correctly defined; if it is, it modifies the value into an integer type
** Parameters: string **&board, int &correct, string potential, int error_type, int cols)
** Pre-conditions: It takes in the board, the correct value, the inputed value, the error type, and the number of columns in the board
** Post-conditions: It modifies the "correct" value variable to contain the correct input value for the program to function
*******************************************************************/
void initializer (string **&board, int &correct, string potential, int error_type, int cols){
   	// JUSTIFICATION FOR LENGTH: the initializer function is so long because it contains the error-handling not only for the initial inputs as integer types instead of strings
	// but it also checks if it is an allowed column length and if the column is full or not; this error checking could have been split into 3 different sections, but it
	// was more concise to have all of it one place
	bool check = true;
	int non_int_present = 0;

	while (check){
		non_int_present = 0;
		for (int i = 0; i < potential.length(); i++){
			if (potential[i] < 48 || potential[i] > 57){
				non_int_present++;
			}
		}
		
		if (non_int_present > 0){
			cout << "The number entered is not an integer, please enter a valid integer" << endl;
			cin >> potential;
		} else {
			correct = atoi(potential.c_str());
			if (error_type == 0){
				if (correct != 1 && correct != 2){
					cout << "Please enter a 1 or 2 value for players" << endl;
					cin >> potential;
				} else {
					check = false;
				}
			} else if (error_type == 1){
				if (correct < 4 || correct >  20){
					cout <<"Please enter a 4-20 value" << endl;
					cin >> potential;
				} else {
					check = false;
				}
			} else if (error_type == 3){
				if (correct < 1 || correct > cols){
					cout << "Please enter a 1-" << cols << " value" << endl;
					cin >> potential;
				} else{
					if (board[0][correct-1] != "_"){
						cout << "Column " << correct << " is full, please enter a new value" << endl;
						cin >> potential;
					} else{
						check = false;
					}
				}
			}
		}
	}
}

/******************************************************************* 
** Function: create_board()
** Description: This function creates the output board with a certain number of rows and cols
** Parameters: string **&board, int rows, int cols
** Pre-conditions: It takes in the game board, along with the rows and columns
** Post-conditions: It prints out the board with a checkered pattern and X's and O's representing the players' pieces
*******************************************************************/
void create_board (string **&board, int rows, int cols){
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			if (board[i][j] == ""){
				board[i][j] = "_";
			}
			if (i % 2 == 0 && j % 2 == 0){
				cout << "|\033[30;47m " << board[i][j] << " ";
			}else if (i % 2 == 1 && j % 2 == 1){
				cout << "|\033[30;47m " << board[i][j] << " ";
			}else{
				cout << "|\033[0m " << board[i][j] << " ";
			}
			cout << "\033[0m";

		}
 		cout << endl;
	}
	cout << endl;
}

/******************************************************************* 
** Function: first_turn();
** Description: It determines whether or not the player, during one-player mode, would like to go first or not
** Parameters: int &turn
** Pre-conditions: It accepts the turn number
** Post-conditions: Returns a modified turn number to reflect the player's decision to go first or not
*******************************************************************/
void first_turn(int &turn){
	bool check = true;	
	string decision = "";
	cout << "Would you like to go first? " << endl;
	
	while (check){
		cin >> decision;
		if (decision == "yes"){
			turn = 0;
			check = false;
		} else if (decision == "no"){
			turn = 1;
			check = false;
		} else {
			cout << "Error: invalid input entered, please enter a yes or no value: " << endl;
		}
	}
}

/******************************************************************* 
** Function: change()
** Description: Adds the pieces played by the player's column input to the board array
** Parameters: string **&board, int move, int player, int rows, int cols
** Pre-conditions: It takes in the board array, the column entered, the player that entered that, and the size of the board
** Post-conditions: It modifies the board to contain the player's newest move
*******************************************************************/
void change(string **&board, int move, int player, int rows, int cols){
	for (int i = (rows-1); i >= 0; i--){
		if (board[i][move] == "_"){
			if (player == 0){
				board[i][move] = "X";
				i=0;
			} else{
				board[i][move] = "O";
				i=0;
			}
		}
	}
}	

/******************************************************************* 
** Function: winner()
** Description: Determining if a player's latest move has either made them a winner, or if they had created a tie situation
** Parameters: string **& board, int turn, int players, int rows, int cols, int mode)
** Pre-conditions: the board, the current turn, the number of players, the size of the board is taken in 
** Post-conditions: if there is a winner / tie, the function prints it and ends the game (return false); else it continues the game (return true)
*******************************************************************/
bool winner(string **& board, int turn, int players, int rows, int cols){
   	// JUSTIFICATION FOR LENGTH: the winner function contains not only ALL of the checks for wins, but also prints out the winner; had I split each win check into a separate function it would have
	// required less lines per function, but it was more conceptially easier for me to combine all the checks into one place
	
	// int mode and int potential are only used for the computer to check against wins
	int wins = 0;
	int tie_check = 0;

	// checking rows for winners
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < (cols-3); j++){
			if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3]){
				if (board[i][j] != "_" ){
					wins++;
				}
			} 
		}
	}

	// checking columns for winners
	for (int i = 0; i < cols; i++){
		for (int j = 0; j < (rows-3); j++){
			if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j+2][i] == board[j+3][i]){
				if (board[j][i] != "_" ){
					wins++;
				}
			} 
		}
	}

	// checking diagonals from up  to down for winners
	for (int i = 0; i < (cols-3); i++){
		for (int j = 0; j < (rows-3); j++){
			if (board[j][i] == board[j+1][i+1] && board[j+1][i+1] == board[j+2][i+2] && board[j+2][i+2] == board[j+3][i+3]){
				if (board[j][i] != "_" ){
					wins++;
				}
			} 
		}
	}

	// checking diagonals from down  to up  for winners
	for (int i = 0; i < (cols-3); i++){
		for (int j = (rows-1); (j-2)> 0; j--){
			if (board[j][i] == board[j-1][i+1] && board[j-1][i+1] == board[j-2][i+2] && board[j-2][i+2] == board[j-3][i+3]){
				if (board[j][i] != "_" ){
					wins++;
				}
			} 
		}
	}

	if (wins == 0){
		// checking for ties
		for (int i = 0; i < cols; i++){
			if (board[0][i] != "_"){
				tie_check++;
			}
		}

		if (tie_check == cols){
			cout << "It is a tie! No one wins" << endl;
			return false;
		} else{
			return true;
		}
	} else{
		if ((turn % 2) == 0){
			cout << "Player 1 has won the game" << endl;
		} else{
		if (players == 1){
			cout << "Computer has won the game" << endl;
		} else {
			cout << "Player 2 has won the game" << endl;
		}
	}
	return false;
}
}

/******************************************************************* 
** Function: computer();
** Description: the dumb AI computer algorithm that creates a move for the computer, randomly
** Parameters: string **&board, int &move, int rows, int cols
** Pre-conditions: It takes in the board, the current move, and the size of the board
** Post-conditions: It modifies the move function to hold the computer's move
*******************************************************************/
void computer(string **&board, int &move, int rows, int cols){
	bool check = true;
	while (check){
		move = rand () % cols;
		if (board[0][move] == "_"){
			check = false;
		} 
	}
}

/******************************************************************* 
** Function: next_move()
** Description: Prompts the user to enter their moves and changes the board by calling upon other functions
** Parameters: string **& board, int turn, int players, int rows, int cols
** Pre-conditions: the board, the current turn, the number of players, and the size of the board are taken in 
** Post-conditions: It completes a "round" of the game by accepting a player input, and modifying the board accordingly
*******************************************************************/
void next_move(string **& board, int turn, int players, int rows, int cols){
   	// JUSTIFICATION FOR LENGTH: the next_move function is over 15 lines because it contains the code for both a player 1 and player 2 / computer move (this could have been split 
	// into three different functions, but it fetl more concise to combine these into one)
	string move_check = "0";
	int move = 0;
	bool check = true;
	
	if ((turn % 2) ==  0){
		
		cout <<"Player 1, enter in a column" << endl;
		cin >> move_check;
		initializer (board, move, move_check, 3, cols);
		move--;
		change(board, move, 0, rows, cols);
		

	} else {
		if (players == 2){
		
		cout <<"Player 2, enter in a column" << endl;
		cin >> move_check;
		initializer (board, move, move_check, 3, cols);
		move--;
		change(board, move, 1, rows, cols);
		

		} else {
			computer (board, move, rows, cols);
			cout << "Computer is playing this turn" << endl;
			change(board, move, 1, rows, cols);
		}
	}
}

/******************************************************************* 
** Function: mode()
** Description: The function that runs an entire game until a win/tie is declared in a while loop
** Parameters: string **&board, int &turn, int &players, bool win, int rows, int cols
** Pre-conditions: The board, turn number, number of players, the win condition check, and the size of the board are taken in 
** Post-conditions: An entire game is run; this function is called each time the user would like to repeat the entire program
*******************************************************************/
void mode(string **&board, int &turn, int &players, bool win, int rows, int cols){
	if (players == 1){
		first_turn(turn);
	}
	create_board(board, rows, cols);
	while (win){
		next_move(board, turn, players, rows, cols);
		create_board(board, rows, cols);
		win = winner (board, turn, players, rows, cols);
		turn++;
	}
}

// MAIN FUNCTION
int main (int argc, char** argv){
	// JUSTIFICATION FOR LENGTH: the main function is over 15 lines long because it not only contains all of the function calls, but it also contains all of the variable
	// initializations (including arrays) which adds to it's length
   	srand (time(NULL));
	string players_check = "0";
	string rows_check = "0";
	string cols_check = "0";
	bool repeat = true;
	
	// Error handling in case argc inputs is not 4
	if (argc == 4){
		players_check = argv[1];
		rows_check = argv[2];
		cols_check = argv[3];
	} else{
		cout << "You have started the program with the wrong number of command line inputs" << endl;
		cout << "Please re-input values as prompted" << endl;
		players_check = "0";
		rows_check = "0";
		cols_check = "0";
	}

	while (repeat){
		int players = 0;
		int rows = 0;
		int cols = 0;
		int turn = 0;
		bool win = true;
		string repeat_response = "";

		// initializing a dummy array for the initializer function 
			// this is necessary as the initializer function doesn't need a board input to check through the user inputed 
			// values for the row, column, and players; however, it is necessary for later function usage
			// initializing the actual board array prior to the creation of board leads to an incorrectly sized array;
		string **dummy = new string*[rows];
		for (int i = 0; i < rows; i++){
			dummy[i] = new string[cols];
		}

		cout << "Checking if the value for players is correct" << endl;
		initializer(dummy, players, players_check, 0, 0);
		cout << "Checking if the value for rows is correct" << endl;
		initializer(dummy, rows, rows_check, 1, 0);
		cout << "Checking if the value for cols is correct" << endl;
		initializer(dummy, cols, cols_check, 1, 0);
		cout << "All values have been correctly inputed, initializing the game" << endl;
		
		// initializing the board dynamically
		string **board = new string*[rows];
		for (int i = 0; i < rows; i++){
			board[i] = new string[cols];
		}

		// the function that initializes the game
		mode(board, turn, players, win, rows, cols);
			
		// deleting the board
		for (int i = 0; i < rows; i++){
			delete [] board[i];
		}
		delete [] board;
		
		cout << endl;
		cout << "Would you like to run again?" << endl;
	
		bool check = true;	
		while (check){
			cin >> repeat_response;
			if (repeat_response != "yes" && repeat_response != "no"){
				cout << "Error: please input a yes or no answer" << endl;
			} else{
				if (repeat_response == "yes"){
					players_check = "0";
					rows_check = "0";
					cols_check = "0";
					check = false;
				} else{
					repeat = false;
					check = false;
				}
			}
		}
	}
}



