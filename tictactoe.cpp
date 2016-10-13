//Sanil Hattangadi, 10/13/16, we play tic tac toe, alternates turns with xs and os. counts wins
#include <iostream>
#include <cstring>
using namespace std;
//methods i will be using
void printBoard (char (*board)[3]);
bool checkWin (char (*board)[3], char player);
void resetBoard (char(*board)[3]);
bool checkTie (char (*board)[3]);
//go through first row and label 1, 2, 3
void printBoard (char (*board)[3]){//3 initializes 3 rows
  cout << "\t1\t2\t3" << endl;
  //go thrugh first row and label a; second row and label b
  cout << "a\t" << board[0][0] << '\t' << board[0][1] << '\t' << board [0][2] << endl;
  cout << "b\t" << board[1][0] << '\t' << board [1][1] << '\t' << board [1][2] << endl;
  cout << "c\t" << board[2][0] << '\t' << board[2][1] << '\t' << board [2][2] << endl;
}
//go through board and give each space a blank
void resetBoard (char (*board)[3]){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j <3; j++){
      board[i][j] = ' ';
      }
  }
}

int main(){
  char X_Move = 'X';
  char O_Move = 'O';
  char X_Turn = 'X';
  char O_Turn = 'O';
  int BLANK = ' ';
  int xwins = 0;
  int owins = 0;
  int turn = X_Turn;
  char input[5];
  char board[3][3];
  char yesno[10];
  bool stillPlaying = true;
  while (stillPlaying == true) {
    resetBoard(board);
    printBoard(board);
    turn = X_Move;
    while (checkWin(board, X_Move) == false && checkWin(board, O_Move) == false && checkTie(board) == false){
      cout << "Enter a letter followed by a number" << endl;
      cin >> input;
      if (strlen(input) !=2){ //if string length isnt equal to 2
	cout << "Enter a letter followed by a number" << endl;
      }
      else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){//if the first character isnt a, b, or c
	cout << "Row must be an a, b,or c." << endl;
      }
      else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){// if second character isnt 1,2, or 3
	cout << "Column must be a 1, 2, or 3." << endl;
      }
      //if correct input and space they type is blank
      else {
	int row = input[0]-'a';
	int column = input[1] - '1';
	if (board[row][column] == BLANK){
	  if (turn == X_Move){
	    cout << board[row][column] << endl;
	    board [row][column] = X_Turn;//place an x
	    turn = O_Move;//o turn now
	  }
	  else {
	    board [row][column] = O_Turn;//palce an o
	    turn = X_Move;// x move now
	   
	  }
	  printBoard(board);
	}
	else {
	  cout << "There's a piece there." << endl;
	}
       }
      if (checkWin(board, X_Move) == true){
	cout << "X Wins! Play again?" << endl;
	xwins++;
	cout << "X has won:" << xwins << endl;
	cout << "O has won:" << owins << endl;
	cin >> yesno; //put whatever the user inputs into the string yesno
	if (0 == strcmp(yesno, "y")){
	  stillPlaying = true;
	  resetBoard(board);
	  printBoard(board);
	  turn = X_Move;
	}
	else {
	  stillPlaying= false;
        }
      }
      //if O wins
      else if (checkWin(board, O_Move) == true){
	cout << "O Wins! Play again?" << endl;
	owins++;//add 1 o the amount of times ) has won
	cout << "X has won:" << xwins << endl;//say this
	cout << "O has won:" << owins << endl;
	cin >> yesno; //put whatever the user inputs into the string yesno
	if (0 == strcmp(yesno, "y")){
	  stillPlaying = true;
	  resetBoard(board);
	  printBoard(board);
	  turn = X_Move;
	}
	else {
	  stillPlaying= false;
	}
      }
      //if theres a tie
      else if (checkTie(board) == true){
	cout << "It's a tie! Play again?" << endl; // say this
	cin >> yesno; //put whatever the user inputs into the string yesno
	if (0 == strcmp(yesno, "y")){//if yesno tring = y
	  stillPlaying = true;
	  resetBoard(board);
	  printBoard(board);
	  turn = X_Move;
	}
	else {//if string yesno doesnt equal y
	  stillPlaying= false;
	}
      }
    }
  }
}
//check ties; goes through each row and column and if theres a blank space, say false
bool checkTie (char (*board)[3]){
  int BLANK = ' ';
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK){
	return false;
      }
    }
  }
  return true;
}
//checks all the possible win arrangements and calls in X and O player along with the board
bool checkWin (char (*board)[3], char player){
  if (board[0][0] == player &&
      board[0][1] == player &&
      board[0][2] == player ){
    return true;
  }
  if (board [0][0] == player &&
      board [1][1] == player &&
      board [2][2] == player){
    return true;
  }
  if (board [1][0] == player &&
      board [1][1] == player &&
      board [1][2] == player){
    return true;
  }
  if (board [2][0] == player &&
      board [2][1] == player &&
      board [2][2] == player){
    return true;
  }
  if (board [0][1] == player &&
      board [1][1] == player &&
      board [2][1] == player){
    return true;
  }
  if (board [0][0] == player &&
      board [1][0] == player &&
      board [2][0] == player){
    return true;
  }
  if (board [0][2] == player &&
      board [1][2] == player &&
      board [2][2] == player){
    return true;
  }
  if (board [0][2] == player &&
      board [1][1] == player &&
      board [2][0] == player){
    return true;
  }
  return false;
}
