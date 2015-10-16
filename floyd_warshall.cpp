#include <iostream>
#include <list>
#include <climits>

struct node {
  std::list< std::pair<int, int> > _adjacency_list;
};

void addEdge(node** graph, int src, int dst, int weight) {
  graph[src]->_adjacency_list.push_back(std::make_pair(dst, weight));
}

void floyd_warshall(node** graph, int** distances, int n) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      distances[i][j] = INT_MAX;
    }
  }
  for(int i = 0; i < n; ++i) {
    distances[i][i] = 0;
  }
  for(int i = 0; i < n; ++i) {
    for(std::list< std::pair<int, int> >::iterator it = graph[i]->_adjacency_list.begin();
        it != graph[i]->_adjacency_list.end(); ++it) {
      distances[i][it->first] = it->second;
    }
  }
  for(int k = 0; k < n; ++k) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if((distances[i][k] != INT_MAX) && (distances[k][j] != INT_MAX) &&
           (distances[i][k] + distances[k][j] < distances[i][j])) {
          distances[i][j] = distances[i][k] + distances[k][j];
        }
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
  int **distances = new int*[n];
  for(int i = 0; i < n; ++i) {
    distances[i] = new int[n];
  }
  floyd_warshall(graph, distances, n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(distances[i][j] != INT_MAX) std::cout << distances[i][j];
      else std::cout << '*';
      std::cout << ' ';
    }
    std::cout << '\n';
  }
}
