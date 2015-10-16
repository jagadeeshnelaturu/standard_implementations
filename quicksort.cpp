#include <iostream>
#include <cstdlib>

int partition(int* vals, int left, int right) {
  int index = rand() % (right - left + 1) + left;
  int lessCount = 0;
  for(int i = left; i <= right; ++i) {
    lessCount += (vals[i] < vals[index]);
  }
  std::swap(vals[index], vals[left + lessCount]);
  int l = left, r = right;
  while(true) {
    if((l == left + lessCount) || (r == left + lessCount)) {
      break;
    }
    else if(vals[l] < vals[left + lessCount]) {
      ++l;
    }
    else if(vals[r] > vals[left + lessCount]) {
      --r;
    }
    else {
      std::swap(vals[l], vals[r]);
    }
  }
  return left + lessCount;
}

void quicksort_helper(int* vals, int left, int right) {
  if(left < right) {
    int mid = partition(vals, left, right);
    quicksort_helper(vals, left, mid - 1);
    quicksort_helper(vals, mid + 1, right);
  }
}

void quicksort(int* vals, int n) {
  quicksort_helper(vals, 0, n - 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cout << "Number of elements: ";
  std::cin >> n;
  int *vals = new int[n];
  std::cout << "Elements: ";
  for(int i = 0; i < n; ++i) {
    std::cin >> vals[i];
  }
  srand(time(NULL));
  quicksort(vals, n);
  for(int i = 0; i < n; ++i) {
    std::cout << vals[i] << ' ';
  }
  std::cout << '\n';
}
