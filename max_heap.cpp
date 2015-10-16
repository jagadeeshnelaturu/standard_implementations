#include <iostream>

inline int left(int i) {
  return 2*i + 1;
}

inline int right(int i) {
  return 2*i + 2;
}

inline int parent(int i) {
  return (i - 1) / 2;
}

inline void swap_elements(int* array, int index1, int index2) {
  array[index1] = array[index1] + array[index2] - (array[index2] = array[index1]);
}

bool is_max_heap(int* array, int length) {
  for(int i = 0; i < length; ++i) {
    if((left(i) < length) && (array[i] < array[left(i)])) return false;
    if((right(i) < length) && (array[i] < array[right(i)])) return false;
  }
  return true;
}

void max_heapify_recursive(int* array, int length, int startIndex) { 
  // assuming both subtrees of node(i) are max-heaps
  int largestIndex;
  if((left(startIndex) < length) && (array[left(startIndex)] > array[startIndex])) {
    largestIndex = left(startIndex);
  }
  else largestIndex = startIndex;
  if((right(startIndex) < length) && (array[right(startIndex)] > array[startIndex])) {
    largestIndex = right(startIndex);
  }
  if(largestIndex != startIndex) {
    swap_elements(array, startIndex, largestIndex);
    max_heapify_recursive(array, length, largestIndex);
  }
}

void max_heapify_iterative(int* array, int length, int startIndex) {
  int current = startIndex;
  while(true) {
    int largestIndex;
    if((left(current) < length) && (array[left(current)] > array[current])) {
      largestIndex = left(current);
    }
    else largestIndex = current;
    if((right(current) < length) && (array[right(current)] > array[largestIndex])) {
      largestIndex = right(current);
    }
    if(largestIndex != current) {
      swap_elements(array, current, largestIndex);
      current = largestIndex;
    }
    else break;
  }
}

void build_max_heap(int* array, int length) {
  for(int j = (length / 2) - 1; j >= 0; --j) {
    max_heapify_iterative(array, length, j);
  }
}

void heapsort(int* array, int length) {
  for(int i = 0; i < length; ++i) {
    build_max_heap(array, length - i);
    swap_elements(array, 0, length - i - 1);
  }
}

int maximum(int* array) {
  return array[0];
}

int extract_max(int* array, int length) {
  int max = array[0];
  array[0] = array[length - 1];
  max_heapify_iterative(array, length - 1, 0);
  return max;
}

int main() {
  int n;
  std::cin >> n;
  int* a = new int(n);
  for(int i=0;i<n;++i) {
    std::cin >> a[i];
  }
  build_max_heap(a, n);
  for(int i = 0; i < n; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << '\n';
  std::cout << extract_max(a, n) << '\n';
  for(int i = 0; i < n - 1; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << '\n';
}
