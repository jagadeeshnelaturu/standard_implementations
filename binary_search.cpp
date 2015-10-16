#include <iostream>

int binary_search(int* vals, int n, int key) {
  int l = 0, r = n - 1, mid;
  while(l <= r) {
    mid = ((l + r) >> 1);
    if(key < vals[mid]) {
      r = mid - 1;
    }
    else if(key == vals[mid]) {
      return mid;
    }
    else if(key > vals[mid]) {
      l = mid + 1;
    }
  }
  return -1;
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
  std::cout << "Enter element whose index is required: ";
  int key;
  std::cin >> key;
  std::cout << "Required index: " << binary_search(vals, n, key) << '\n';
}
