// Given a tree with root 0, find if one node is ancestor of another

#include <iostream>
#include <stack>
#include <list>


struct node {
  std::list<int> _adjacency_list;
};

void addEdge(node** graph, int n1, int n2) {
  graph[n1]->_adjacency_list.push_back(n2);
}

void dfs(node** graph, int* startTimes, int* endTimes, int root, int size) {
  #define WHITE 0
  #define GRAY 1
  #define BLACK 2

  int time = 0, *color = new int[size], current;
  for(int i = 0; i < size; ++i) {
    color[i] = WHITE;
  }
  std::stack<int> s;
  s.push(root);
  color[root] = GRAY;
  while(!s.empty()) {
    current = s.top();
    if(color[current] == BLACK) {
      endTimes[current] = time++;
      s.pop();
    }
    else {
      startTimes[current] = time++;
      for(std::list<int>::iterator it = graph[current]->_adjacency_list.begin();
          it != graph[current]->_adjacency_list.end(); ++it) {
        if(color[*it] == WHITE) {
          s.push(*it);
          color[*it] = GRAY;
        }
      }
      color[current] = BLACK;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, temp1, temp2;
  std::cin >> n;
  node **tree = new node*[n];
  for(int i = 0; i < n; ++i) {
    tree[i] = new node();
  }
  for(int i = 0; i < n - 1; ++i) {
    std::cin >> temp1 >> temp2;
    addEdge(tree, temp1, temp2);
    addEdge(tree, temp2, temp1);
  }
  int *startTimes = new int[n], *endTimes = new int[n];
  dfs(tree, startTimes, endTimes, 0, n);
  int m;
  std::cin >> m;
  while(m--) {
    std::cin >> temp1 >> temp2;
    if((startTimes[temp1] < startTimes[temp2]) &&
       (endTimes[temp2] < endTimes[temp1])) {
      std::cout << temp1 << " is ancestor of " << temp2 << '\n';
    }
    else if((startTimes[temp2] < startTimes[temp1]) &&
       (endTimes[temp1] < endTimes[temp2])) {
      std::cout << temp2 << " is ancestor of " << temp1 << '\n';
    }
    else {
      std::cout << "No\n";
    }
  }
}

/*Input format
7
0 4
0 6
1 4
2 6
3 4
5 6
6
0 1
2 4
1 6
3 6
3 4
2 6
*/

