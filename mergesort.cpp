#include <iostream>

void merge(int* vals, int left, int mid, int right) {
  int *copy1 = new int[mid - left], *copy2 = new int[right - mid + 1];
  for(int i = left; i < mid; ++i) {
    copy1[i - left] = vals[i];
  }
  for(int i = mid; i <= right; ++i) {
    copy2[i - mid] = vals[i];
  }
  int i = 0, j = 0;
  for(int k = left; k <= right; ++k) {
    if(i == mid - left) {
      vals[k] = copy2[j];
      ++j;
    }
    else if(j == right - mid + 1) {
      vals[k] = copy1[i];
      ++i;
    }
    else if(copy1[i] < copy2[j]) {
      vals[k] = copy1[i];
      ++i;
    }
    else if(copy1[i] > copy2[j]) {
      vals[k] = copy2[j];
      ++j;
    }
  }
}

void mergesort_helper(int* vals, int left, int right) {
  if(left < right) {
    int mid = ((left + right) >> 1);
    mergesort_helper(vals, left, mid);
    mergesort_helper(vals, mid + 1, right);
    merge(vals, left, mid + 1, right);
  }
}

void mergesort(int* vals, int n) {
  mergesort_helper(vals, 0, n - 1);
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
  mergesort(vals, n);
  for(int i = 0; i < n; ++i) {
    std::cout << vals[i] << ' ';
  }
  std::cout << '\n';
}
