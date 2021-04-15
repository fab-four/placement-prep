#include "dsu.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Graph {

public:
  Graph(int _v) : m_v(_v) {}
  inline void addEdge(int u, int v, int w) { m_edge_list.push_back({w, u, v}); }
  int kruskal();

private:
  vector<vector<int>> m_edge_list;
  size_t m_v;
};

int Graph::kruskal() {
  sort(begin(m_edge_list), end(m_edge_list));
  DSU dsu(m_v);
  int mst_cost = 0;
  for (const auto &edge : m_edge_list) {
    int weight = edge[0];
    int src = edge[1];
    int dest = edge[2];
    if (dsu.unite(src, dest)) {
      mst_cost += weight;
    }
  }
  return mst_cost;
}

int main() {
  Graph g(4);
  g.addEdge(0, 1, 1);
  g.addEdge(1, 3, 4);
  g.addEdge(3, 2, 4);
  g.addEdge(2, 0, 2);
  g.addEdge(0, 3, 2);
  g.addEdge(1, 2, 2);
  cout << g.kruskal() << '\n';
  return 0;
}
