#include <iostream>
#include <list>
#include <climits>

struct node {
  std::list< std::pair<int, int> > _adjacency_list;
};

void addEdge(node** graph, int src, int dst, int weight) {
  graph[src]->_adjacency_list.push_back(std::make_pair(dst, weight));
}

void bellman_ford(node **graph, int n, int source, int* distances) {
  for(int i = 0; i < n; ++i) {
    distances[i] = INT_MAX;
  }
  distances[source] = 0;
  for(int i = 1; i < n; ++i) {
    int current = 0;
    while(current < n) {
      for(std::list< std::pair<int, int> >::iterator it = graph[current]->_adjacency_list.begin();
          it != graph[current]->_adjacency_list.end(); ++it) {
        if((distances[current] != INT_MAX) &&
           (distances[current] + it->second < distances[it->first])) {
          distances[it->first] = distances[current] + it->second;
        }
      }
      ++current;
    }
  }
  int current = 0;
  while(current < n) {
    for(std::list< std::pair<int, int> >::iterator it = graph[current]->_adjacency_list.begin();
        it != graph[current]->_adjacency_list.end(); ++it) {
      if((distances[current] != INT_MAX) &&
         (distances[current] + it->second < distances[it->first])) {
        std::cout << "Graph contains negative edge cycle\n";
        return;
      }
    }
    ++current;
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
  bellman_ford(graph, n, 0, distances);
  for(int i = 0; i < n; ++i) {
    std::cout << distances[i] << ' ';
  }
  std::cout << '\n';
}

/*Example input
6
8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 1 1
3 2 5
4 3 -3
5 0 1
*/
