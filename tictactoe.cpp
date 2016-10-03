#include <iostream>
using namespace std;

void printBoard (char (*board)[3]);
bool checkWin (char (*board)[3], char player);
void resetBoard (char (*board)[3]);

void printBoard (char (*board)[3]){//3 initializes 3 rows
  cout << "\t1\t2\t3" << endl;
  cout << "a\t" << board[0][0] << '\t' << board[0][1] << '\t' << board [0][2] << endl;
  cout << "b\t" << board[1][0] << '\t' << board [1][1] << '\t' << board [1][2] << endl;
  cout << "c\t" << board[2][0] << '\t' << board[2][1] << '\t' << board [2][2] << endl;
}
void resetBoard (char (*board)[3]){
  for (int i; i < 3; i++){
    for (int j; j <3; j++){
      board[i][j] = 0;
      }
  }
}

int main(){
  char board[3][3];
  boolean stillPlaying = true;
  while (stillPlaying == true) {
    while (
  }
  resetBoard(board);
  printBoard(board);
  return 0;
}

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
