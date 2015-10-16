#include <iostream>

#define SIZE 1024

class queue {
  int _vals[SIZE], _front, _back;
  bool _empty;

 public:
  queue() {
    _front = 0;
    _back = 0;
    _empty = true;
  }

  bool empty() {
    return _empty;
  }

  void push_back(int x) {
    if(_empty) {
      _vals[0] = x;
      _empty = false;
    }
    else {
      int new_back = (_back + 1) % SIZE;
      if(new_back == _front) {
        std::cout << "Queue full\n";
        return;
      }
      _back = new_back;
      _vals[_back] = x;
    }
  }

  int front() {
    if(_empty) {
      std::cout << "Queue empty\n";
      return -1;
    }
    return _vals[_front];
  }

  void pop_front() {
    if(_empty) {
      std::cout << "Queue empty\n";
    }
    else if(_front == _back) {
      _empty = true;
      _front = 0;
      _back = 0;
    }
    else {
      _front = (_front + 1) % SIZE;
    }
  }

  void print() {
    if(_empty) {
      std::cout << '\n';
      return;
    }
    int i = _front;
    while(true) {
      std::cout << _vals[i];
      if(i == _back) break;
      i = (i + 1) % SIZE;
    }
    std::cout << '\n';
  }
};

int main() {
  queue q;
  q.print();
  q.push_back(1);
  q.print();
  q.push_back(2);
  q.print();
  q.push_back(3);
  q.print();
  q.push_back(4);
  q.print();
  q.push_back(5);
  q.print();
  q.push_back(6);
  q.print();
  std::cout << q.front() << '\n';
  q.pop_front();
  q.print();
  std::cout << q.front() << '\n';
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.push_back(5);
  q.print();
  q.push_back(6);
  q.print();
  std::cout << q.front() << '\n';
}
