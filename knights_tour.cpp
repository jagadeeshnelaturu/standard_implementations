#include <iostream>

#define MOVES 8

bool valid(int** board, int x, int y, int height, int width) {
  return ((x >= 0) && (x < height) && (y >= 0) && (y < width) && (board[x][y] == -1));
}

bool solve(int** board, int x, int y, int height, int width, int (&moves)[MOVES][2], int count) {
  if(count == height * width) return true;
  for(int i = 0; i < MOVES; ++i) {
    int xnew = x + moves[i][0], ynew = y + moves[i][1];
    if(!valid(board, xnew, ynew, height, width)) continue;
    board[xnew][ynew] = count;
    if(solve(board, xnew, ynew, height, width, moves, count + 1)) {
      return true;
    }
    board[xnew][ynew] = -1;
  }
  return false;
}

bool tour(int** board, int height, int width, int (&moves)[MOVES][2]) {
  int startx = 0, starty = 0;
  board[startx][starty] = 0;
  return solve(board, startx, starty, height, width, moves, 1);
}

int main() {
  int height, width;
  std::cin >> height >> width;
  int **board = new int*[height];
  for(int i = 0; i < height; ++i) {
    board[i] = new int[width];
    for(int j = 0; j < width; ++j) {
      board[i][j] = -1;
    }
  }
  int moves[MOVES][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
  if(!tour(board, height, width, moves)) {
    std::cout << "Not possible\n";
    return 0;
  }
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
}
