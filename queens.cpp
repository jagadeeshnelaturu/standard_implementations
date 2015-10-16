#include <iostream>

bool safe(bool** board, int row, int column, int n) {
  for(int i = 0; i < column; ++i) {
    if(board[row][i]) return false;
  }
  int temp1 = row - 1, temp2 = column - 1;
  while((temp1 >= 0) && (temp2 >= 0)) {
    if(board[temp1][temp2]) return false;
    --temp1;
    --temp2;
  }
  temp1 = row + 1;
  temp2 = column - 1;
  while((temp1 < n) && (temp2 >= 0)) {
    if(board[temp1][temp2]) return false;
    ++temp1;
    --temp2;
  }
  return true;
}

/*bool solve(bool** board, int column, int n) {
  if(column == n) return true;
  for(int i = 0; i < n; ++i) {
    if(safe(board, i, column, n)) {
      board[i][column] = 1;
      if(solve(board, column + 1, n)) {
        return true;
      }
      board[i][column] = 0;
    }
  }
  return false;
}

bool queens(bool** board, int n) {
  return solve(board, 0, n);
}*/

void solve(bool** board, int column, int n, int* solutions) {
  if(column == n) ++(*solutions);
  for(int i = 0; i < n; ++i) {
    if(safe(board, i, column, n)) {
      board[i][column] = 1;
      solve(board, column + 1, n, solutions);
      board[i][column] = 0;
    }
  }
}

int queens(bool** board, int n) {
  int solutions = 0;
  solve(board, 0, n, &solutions);
  return solutions;
}

int main() {
  int n;
  std::cin >> n;
  bool** board = new bool*[n];
  for(int i = 0; i < n; ++i) {
    board[i] = new bool[n];
    for(int j = 0; j < n; ++j) {
      board[i][j] = false;
    }
  }
  /*bool solution = queens(board, n);
  if(!solution) {
    std::cout << "No solution\n";
    return 0;
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }*/
  int numSolutions = queens(board, n);
  std::cout << numSolutions << '\n';
}
