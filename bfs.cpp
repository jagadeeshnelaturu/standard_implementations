#include <iostream>
#include <list>
#include <queue>
#include <climits>

struct node {
  std::list<int> _adjacency_list;
};

void addEdge(node** graph, int n1, int n2) {
  graph[n1]->_adjacency_list.push_back(n2);
}

void bfs(node** graph, int n, int root, int* distances) {
  for(int i = 0; i < n; ++i) {
    distances[i] = INT_MAX;
  }
  std::queue<int> q;
  q.push(root);
  distances[root] = 0;
  while(!q.empty()) {
    int temp = q.front();
    for(std::list<int>::iterator it = graph[temp]->_adjacency_list.begin();
        it != graph[temp]->_adjacency_list.end(); ++it) {
      if(distances[*it] == INT_MAX) {
        q.push(*it);
        distances[*it] = distances[temp] + 1;
      }
    }
    q.pop();
  }
}

int main() {
  int n;
  std::cin >> n;
  node **graph = new node*[n];
  for(int i = 0; i < n; ++i) {
    graph[i] = new node();
  }
  int m;
  std::cin >> m;
  int temp1, temp2;
  while(m--) {
    std::cin >> temp1 >> temp2;
    addEdge(graph, temp1, temp2);
  }
  int *distances = new int[n];
  bfs(graph, n, 0, distances);
  for(int i = 0; i < n; ++i) {
    if(distances[i] != INT_MAX) {
      std::cout << distances[i];
    }
    else {
      std::cout << '*';
    }
    std::cout << ' ';
  }
  std::cout << '\n';
}

/*int main() {
  const int n = 8, m = 64;
  node **graph = new node*[m];
  for(int i = 0; i < m; ++i) {
    graph[i] = new node();
  }
  for(int i = 0; i < m; ++i) {
    int row = i / n, column = i % n;
    if((row > 0) && (column > 1)) addEdge(graph, i, i - n - 2);
    if((row > 1) && (column > 0)) addEdge(graph, i, i - 2 * n - 1);
    if((row > 1) && (column < n - 1)) addEdge(graph, i, i - 2 * n + 1);
    if((row > 0) && (column < n - 2)) addEdge(graph, i, i - n  + 2);
    if((row < n - 1) && (column < n - 2)) addEdge(graph, i, i + n + 2);
    if((row < n - 2) && (column < n - 1)) addEdge(graph, i, i + 2 * n + 1);
    if((row < n - 2) && (column > 0)) addEdge(graph, i, i + 2 * n - 1);
    if((row < n - 1) && (column > 1)) addEdge(graph, i, i + n - 2);
  }
  int *distances = new int[m];
  bfs(graph, m, 0, distances);
  for(int i = 0; i < m; ++i) {
    std::cout << distances[i] << ' ';
  }
  std::cout << '\n';
}*/

/*Example input
7
8
0 1
0 2
0 4
1 5
1 6
2 0
2 6
3 4
*/
