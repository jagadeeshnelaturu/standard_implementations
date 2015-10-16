#include <iostream>
#include <algorithm>

int findMedian(int* vals, int size) {
  std::sort(vals, vals + size);
  return vals[size / 2];
}

int partition(int* vals, int left, int right, int x) {
  int index;
  for(index = left; index <= right; ++index) {
    if(vals[index] == x) break;
  }
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

int kth_helper(int* vals, int left, int right, int k) {
  int count = right - left + 1;
  int i, median[(count + 4) / 5];
  for(i = 0; i < count / 5; ++i) {
    median[i] = findMedian(vals + left + 5 * i, 5);
  }
  if(5 * i < count) {
    median[i] = findMedian(vals + left + 5 * i, count % 5);
    ++i;
  }
  int medianOfMedians = ((i == 1) ? median[i - 1] : kth_helper(median, 0, i - 1, i / 2));
  int position = partition(vals, left, right, medianOfMedians);
  if(position - left == k - 1) {
    return vals[position];
  }
  else if(position - left > k - 1) {
    return kth_helper(vals, left, position - 1, k);
  }
  else if(position - left < k - 1) {
    return kth_helper(vals, position + 1, right, k - position + left - 1);
  }
}

int kthSmallest(int* vals, int n, int k) {
  return kth_helper(vals, 0, n - 1, k);
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  int *vals = new int[n];
  for(int i = 0; i < n; ++i) {
    std::cin >> vals[i];
  }
  int k;
  std::cin >> k;
  std::cout << kthSmallest(vals, n, k) << '\n'; //modifies vals
}
