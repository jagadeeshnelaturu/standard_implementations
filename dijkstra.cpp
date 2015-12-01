#include <iostream>
#include <list>
#include <queue>
#include <climits>

struct node {
  std::list< std::pair<int, int> > _adjacency_list;
};

void addEdge(node** graph, int n1, int n2, int weight) {
  graph[n1]->_adjacency_list.push_back(std::make_pair(n2, weight));
}

struct vertex {
  int _index, _distance;

  vertex() {
  }

  vertex(int index, int distance) {
    _index = index;
    _distance = distance;
  }
};

bool operator<(vertex v1, vertex v2) {
  return v1._distance > v2._distance;
}

void dijkstra(node** graph, int n, int root, int* distances) {
  for (int i = 0; i < n; ++i) {
    distances[i] = INT_MAX;
  }
  distances[root] = 0;
  std::priority_queue<vertex> q;
  q.push(vertex(root, 0));
  while(!q.empty()) {
    int front = q.top()._index;
    q.pop();
    for(std::list< std::pair<int, int> >::iterator it = graph[front]->_adjacency_list.begin();
        it != graph[front]->_adjacency_list.end(); ++it) {
      if(distances[it->first] > distances[front] + it->second) {
        distances[it->first] = distances[front] + it->second;
        q.push(vertex(it->first, distances[it->first]));
      }
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
  int src, dst, weight;
  while(m--) {
    std::cin >> src >> dst >> weight;
    addEdge(graph, src, dst, weight);
  }
  int *distances = new int[n];
  dijkstra(graph, n, 0, distances);
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

/*Sample input
9
28
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
1 0 4
7 0 8
2 1 8
7 1 11
3 2 7
5 2 4
8 2 2
4 3 9
5 3 14
5 4 10
6 5 2
7 6 1
8 6 6
8 7 7
*/
