#include <iostream>

void selection_sort(int* vals, int n) {
  int minIndex;
  for(int i = 0; i < n; ++i) {
    minIndex = i;
    for(int j = i + 1; j < n; ++j) {
      if(vals[j] < vals[minIndex]) minIndex = j;
    }
    std::swap(vals[i], vals[minIndex]);
  }
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
  selection_sort(vals, n);
  for(int i = 0; i < n; ++i) {
    std::cout << vals[i] << ' ';
  }
  std::cout << '\n';
}
