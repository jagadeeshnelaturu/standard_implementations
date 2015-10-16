#include <iostream>

int* insertion_sort(int* vals, int n) {
  int *sorted = new int[n], position, k;
  for(int i = 0; i < n; ++i) {
    position = 0;
    while(position < i) {
      if(sorted[position] > vals[i]) break;
      ++position;
    }
    for(k = i - 1; k >= position; --k) {
      sorted[k + 1] = sorted[k];
    }
    sorted[position] = vals[i];
  }
  return sorted;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cout << "Enter number of elements: ";
  std::cin >> n;
  int *vals = new int[n];
  std::cout << "Enter elements: ";
  for(int i = 0; i < n; ++i) {
    std::cin >> vals[i];
  }
  int *sorted = insertion_sort(vals, n);
  for(int i = 0; i < n; ++i) {
    std::cout << sorted[i] << ' ';
  }
  std::cout << '\n';
}
