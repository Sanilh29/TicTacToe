#include <iostream>
#include <cstring>
using namespace std;

void printBoard (char (*board)[3]);
bool checkWin (char (*board)[3], int player);
void resetBoard (char(*board)[3]);
bool checkTie (char (*board)[3]);

void printBoard (char (*board)[3]){//3 initializes 3 rows
  cout << "\t1\t2\t3" << endl;
  cout << "a\t" << board[0][0] << '\t' << board[0][1] << '\t' << board [0][2] << endl;
  cout << "b\t" << board[1][0] << '\t' << board [1][1] << '\t' << board [1][2] << endl;
  cout << "c\t" << board[2][0] << '\t' << board[2][1] << '\t' << board [2][2] << endl;
}
void resetBoard (char (*board)[3]){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j <3; j++){
      board[i][j] = ' ';
      }
  }
}

int main(){
  int X_Move = 1;
  int O_Move = 2;
  int X_Turn = 0;
  int O_Turn = 1;
  int BLANK = 0;
  int turn = X_Turn;
  char input[5];
  char board[3][3];
  bool stillPlaying = true;
  while (stillPlaying == true) {
    resetBoard(board);
    printBoard(board);
    turn = X_Move;
    while (checkWin(board, X_Move) == false && checkWin(board, O_Move) == false && checkTie(board) == false){
      cout << "Enter a letter followed by a number" << endl;
      cin >> input;
      if (strlen(input) !=2){
	cout << "Enter a letter followed by a number" << endl;
      }
      else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
	cout << "Row must be an a, v,or c." << endl;
      }
      else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){
	cout << "Column must be a 1, 2, or 3." << endl;
      }
      else {
	int row = input[0]-'a';
	int column = input[1] - '1';
	if (board[row][column] == BLANK){
	}
      }
      }
  }
  return 0;
}

bool checkTie (char (*board)[3]){
  }
 
bool checkWin (char (*board)[3], int player){
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
