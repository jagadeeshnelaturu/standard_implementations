#include <iostream>
#include <list>
#include <queue>

struct node {
  std::list< std::pair<int, int> > _adjacency_list;
};

void addEdge(node** graph, int n1, int n2, int weight) {
  graph[n1]->_adjacency_list.push_back(std::make_pair(n2, weight));
  graph[n2]->_adjacency_list.push_back(std::make_pair(n1, weight));
}

struct edge {
  int _n1, _n2, _weight;

  edge() {
  }

  edge(int n1, int n2, int weight) {
    _n1 = n1;
    _n2 = n2;
    _weight = weight;
  }

  bool operator<(edge c) const {
    return _weight > c._weight;
  }
};

void prim(node** graph, int* parent, int n, int* weight) {
  std::priority_queue<edge> q;
  for(int i = 0; i < n; ++i) {
    parent[i] = -1;
  }
  int root = 0;
  for(std::list< std::pair<int, int> >::iterator it = graph[root]->_adjacency_list.begin();
      it != graph[root]->_adjacency_list.end(); ++it) {
    q.push(edge(root, it->first, it->second));
  }
  parent[0] = 0;
  while(!q.empty()) {
    edge front = q.top();
    q.pop();
    if(parent[front._n2] != -1) continue;
    parent[front._n2] = front._n1;
    *weight += front._weight;
    for(std::list< std::pair<int, int> >::iterator it = graph[front._n2]->_adjacency_list.begin();
        it != graph[front._n2]->_adjacency_list.end(); ++it) {
      q.push(edge(front._n2, it->first, it->second));
    }
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
  int n1, n2, weight;
  while(m--) {
    std::cin >> n1 >> n2 >> weight;
    addEdge(graph, n1, n2, weight);
  }
  int *parent = new int[n], *min_weight = new int(0);
  prim(graph, parent, n, min_weight);
  std::cout << *min_weight << '\n';
  for(int i = 0; i < n; ++i) {
    std::cout << parent[i] << ' ';
  }
  std::cout << '\n';
}

/*Sample input
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/

/*
5
7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
*/
