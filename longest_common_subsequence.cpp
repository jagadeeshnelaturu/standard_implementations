#include <iostream>

int main() {
  int m;
  std::cin >> m;
  char *x = new char[m];
  for(int i = 0; i < m; ++i) {
    std::cin >> x[i];
  }
  int n;
  std::cin >> n;
  char *y = new char[n];
  for(int i = 0; i < n; ++i) {
    std::cin >> y[i];
  }
  int **values = new int*[m + 1];
  for(int i = 0; i < m + 1; ++i) {
    values[i] = new int[n + 1];
  }
  for(int i = 0; i <= m; ++i) {
    for(int j = 0; j <= n; ++j) {
      if((i == 0) || (j == 0)) {
        values[i][j] = 0;
      }
      else if(x[i - 1] == y[j - 1]) {
        values[i][j] = values[i - 1][j - 1] + 1;
      }
      else {
        values[i][j] = std::max(values[i - 1][j], values[i][j - 1]);
      }
    }
  }
  std::cout << values[m][n] << '\n';
  int i = m, j = n;
  std::string s = "";
  while(true) {
    if((i == 0) || (j == 0)) {
      break;
    }
    else if(values[i][j] == values[i - 1][j - 1] + 1) {
      s = x[i - 1] + s;
      --i;
      --j;
    }
    else if(values[i - 1][j] > values[i][j - 1]) {
      --i;
    }
    else {
      --j;
    }
  }
  std::cout << s << '\n';
}

/*Example input
7
abcbdab
6
bdcaba
*/
