#include <iostream>
#include <vector>
#include <algorithm>

struct interval {
  int _start, _end;

  void set(int start, int end) {
    _start = start;
    _end = end;
  }

};

bool operator<(interval i1, interval i2) {
  if(i1._end != i2._end) return (i1._end < i2._end);
  return i1._start < i2._start;
}

bool intersect(interval i1, interval i2) {
  return ((i1._end > i2._start) && (i2._end > i1._start));
}

int main() {
  int n;
  std::cin >> n;
  interval *vals = new interval[n];
  int temp1, temp2;
  for(int i = 0; i < n; ++i) {
    std::cin >> temp1 >> temp2;
    vals[i].set(temp1, temp2);
  }
  std::vector<interval> optimum;
  std::sort(vals, vals + n);
  optimum.push_back(vals[0]);
  int index = 1, prev = 0;
  while(index < n) {
    if(!intersect(vals[index], vals[prev])) {
      optimum.push_back(vals[index]);
      prev = index;
    }
    ++index;
  }
  std::cout << optimum.size() << '\n';
  for(std::vector<interval>::iterator it = optimum.begin(); it != optimum.end(); ++it) {
    std::cout << "(" << it->_start << ", " << it->_end << ") ";
  }
  std::cout << '\n';
}

/*Input format
7
0 5
2 7
6 16
9 13
10 11
11 21
18 28
*/
