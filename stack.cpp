#include <iostream>

#define MAX_SIZE 1024

class stack {
  int _vals[MAX_SIZE], _size;

 public:
  stack() {
    _size = 0;
  }

  void push(int val) {
    if(_size < MAX_SIZE) {
      _vals[_size] = val;
      ++_size;
    }
    else {
      std::cout << "Insufficient space.\n";
    }
  }

  int top() {
    if(_size) {
      return _vals[_size - 1];
    }
    else {
      std::cout << "Stack empty\n";
      return -1;
    }
  }

  void pop() {
    if(_size) {
      --_size;
    }
    else {
      std::cout << "Stack empty\n";
    }
  }
};

int main() {
  stack s;
  s.pop();
  s.push(1);
  std::cout << s.top() << '\n';
  s.pop();
  s.pop();
  s.pop();
  for(int i = 0; i < 1028; ++i) {
    std::cout << i << '\n';
    s.push(i);
  }
}
