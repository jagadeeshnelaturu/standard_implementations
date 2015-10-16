#include <iostream>

class node {
  int _key, _value;
  node *_left, *_right;
  friend class bst;
 public:
  node() {
  }

  node(int key, int value) {
    _key = key;
    _value = value;
    _left = NULL;
    _right = NULL;
  }
};

class bst {
  node *_root;

 public:
  bst() {
    _root = NULL;
  }

  void insert(int key, int value) {
    if(_root == NULL) {
      _root = new node(key, value);
      return;
    }
    node *current = _root;
    while(true) {
      if(key < current->_key) {
        if(current->_left == NULL) {
          break;
        }
        else {
          current = current->_left;
        }
      }
      else if(key > current->_key) {
        if(current->_right == NULL) {
          break;
        }
        else {
          current = current->_right;
        }
      }
      else if(key == current->_key) {
        return;
      }
    }
    if(key < current->_key) {
      current->_left = new node(key, value);
    }
    else if(key > current->_key) {
      current->_right = new node(key, value);
    }
  }

  int search(int key) {
    node *current = _root;
    while(current != NULL) {
      if(key == current->_key) {
        return current->_value;
      }
      else if(key < current->_key) {
        current = current->_left;
      }
      else if(key > current->_key) {
        current = current->_right;
      }
    }
    return -1;
  }

  void remove(int key) {
    if(_root == NULL) {
      return;
    }
    node *parent, *current = _root;
    while(true) {
      if(key == current->_key) {
        break;
      }
      else if(key < current->_key) {
        if(current->_left == NULL) {
          return;
        }
        parent = current;
        current = current->_left;
      }
      else if(key > current->_key) {
        if(current->_right == NULL) {
          return;
        }
        parent = current;
        current = current->_right;
      }
    }
    if(current == _root) {
      if((current->_left == NULL) && (current->_right == NULL)) {
        delete _root;
        _root = NULL;
      }
      else if(current->_left == NULL) {
        _root = current->_right;
        delete current;
      }
      else if(current->_right == NULL) {
        _root = current->_left;
        delete current;
      }
      else {
        node *parent2 = _root, *current2 = _root->_left;
        while(current2->_right != NULL) {
          parent2 = current2;
          current2 = current2->_right;
        }
        _root = current2;
        if(parent2 != current) {
          parent2->_right = current2->_left;
          _root->_left = current->_left;
        }
        _root->_right = current->_right;
        delete current;
        current = NULL;
      }
      return;
    }
    bool isLeftChild = (parent->_left == current);
    if((current->_left == NULL) && (current->_right == NULL)) {
      delete (isLeftChild ? parent->_left : parent->_right);
      if(isLeftChild) {
        parent->_left = NULL;
      }
      else {
        parent->_right = NULL;
      }
    }
    else if(current->_left == NULL) {
      if(isLeftChild) {
        parent->_left = current->_right;
      }
      else {
        parent->_right = current->_right;
      }
      delete current;
      current = NULL;
    }
    else if(current->_right == NULL) {
      if(isLeftChild) {
        parent->_left = current->_left;
      }
      else {
        parent->_right = current->_left;
      }
      delete current;
      current = NULL;
    }
    else {
      node *parent2 = current, *current2 = current->_left;
      while(current2->_right != NULL) {
        parent2 = current2;
        current2 = current2->_right;
      }
      if(isLeftChild) {
        parent->_left = current2;
      }
      else {
        parent->_right = current2;
      }
      if(parent2 != current) {
        parent2->_right = current2->_left;
        current2->_left = current->_left;
      }
      current2->_right = current->_right;
      delete current;
      if(parent2 == current) parent2 = NULL;
      current = NULL;
    }
  }

  void f(node* n) {
    if(n->_left != NULL) {
      f(n->_left);
    }
    std::cout << n->_key << ": ";
    std::cout << ((n->_left == NULL) ? -1 : n->_left->_key) << ' ';
    std::cout << ((n->_right == NULL) ? -1 : n->_right->_key) << '\n';
    if(n->_right != NULL) {
      f(n->_right);
    }
  }

  void printState() {
    f(_root);
    std::cout << "************\n";
  }

  void print() {
    printInOrder(_root);
    std::cout << '\n';
  }

  void printInOrder(node* n) {
    if(n->_left != NULL) {
      printInOrder(n->_left);
    }
    std::cout << n->_key << ' ';
    if(n->_right != NULL) {
      printInOrder(n->_right);
    }
  }
};

int main() {
  bst b;
  b.insert(4, 1);
  //b.insert(6, 36);
  b.insert(2, 4);
  //b.insert(5, 25);
  //b.insert(1, 1);
  b.insert(3, 9);
  b.insert(7, 49);

  b.printState();
  /*b.remove(6);
  b.printState();
  b.remove(6);
  b.printState();
  b.remove(5);
  b.printState();
  b.remove(1);
  b.printState();*/
  b.remove(4);
  b.printState();
  b.remove(3);
  b.printState();
}
