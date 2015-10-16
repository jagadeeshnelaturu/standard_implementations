#include <iostream>

/* Quick find
struct uf {
  int _size, *_id;

  uf(int n) {
    _size = n;
    _id = new int[n];
    for(int i = 0; i < n; ++i) {
      _id[i] = i;
    }
  }

  void myunion(int p, int q) {
    int pid = _id[p], qid = _id[q];
    for(int i = 0; i < _size; ++i) {
      if(_id[i] == pid) _id[i] = qid;
    }
  }

  bool connected(int p, int q) {
    return (_id[p] == _id[q]);
  }
};*/

/* Quick union
struct uf {
  int _size, *_id;

  uf(int n) {
    _size = n;
    _id = new int[n];
    for(int i = 0; i < n; ++i) {
      _id[i] = i;
    }
  }

 private:
  int root(int i) {
    while(_id[i] != i) i = _id[i];
    return i;
  }

 public:
  void myunion(int p, int q) {
    _id[p] = _id[q];
  }

  bool connected(int p, int q) {
    int rootp = root(p), rootq = root(q);
    return (rootp == rootq);
  }
};*/


/* Weighted quick union
struct uf {
  int _size, *_id, *_sz;

  uf(int n) {
    _size = n;
    _id = new int[n];
    for(int i = 0; i < n; ++i) {
      _id[i] = i;
    }
    _sz = new int[n];
    for(int i = 0; i < n; ++i) {
      _sz[i] = 1;
    }
  }

 private:
  int root(int i) {
    while(_id[i] != i) i = _id[i];
    return i;
  }

 public:
  void myunion(int p, int q) {
    int rootp = root(p), rootq = root(q);
    if(rootp == rootq) return;
    if(_sz[rootp] < _sz[rootq]) {
      _id[rootp] = rootq;
      _sz[rootq] += _sz[rootp];
    }
    else {
      _id[rootq] = rootp;
      _sz[rootp] += _sz[rootq];
    }
  }

  bool connected(int p, int q) {
    int rootp = root(p), rootq = root(q);
    return (rootp == rootq);
  }
};*/

// Weighted quick union with path compression
struct uf {
  int _size, *_id, *_sz;

  uf(int n) {
    _size = n;
    _id = new int[n];
    for(int i = 0; i < n; ++i) {
      _id[i] = i;
    }
    _sz = new int[n];
    for(int i = 0; i < n; ++i) {
      _sz[i] = 1;
    }
  }

 private:
  int root(int i) {
    int parent = i, temp;
    while(_id[parent] != parent) parent = _id[parent];
    while(i != parent) {
      temp = _id[i];
      _id[i] = parent;
      i = temp;
    }
    return parent;
  }

 public:
  void myunion(int p, int q) {
    int rootp = root(p), rootq = root(q);
    if(rootp == rootq) return;
    if(_sz[rootp] < _sz[rootq]) {
      _id[rootp] = rootq;
      _sz[rootq] += _sz[rootp];
    }
    else {
      _id[rootq] = rootp;
      _sz[rootp] += _sz[rootq];
    }
  }

  bool connected(int p, int q) {
    int rootp = root(p), rootq = root(q);
    return (rootp == rootq);
  }
};


int main() {
  int n;
  std::cin >> n;
  uf uf1(n);
  int temp1, temp2, temp3;
  while(std::cin >> temp1 >> temp2 >> temp3) {
    if(temp1) uf1.myunion(temp2, temp3);
    else std::cout << uf1.connected(temp2, temp3) << '\n';
  }
}
