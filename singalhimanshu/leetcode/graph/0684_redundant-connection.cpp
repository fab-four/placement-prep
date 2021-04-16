// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/redundant-connection/

class DSU {
public:
  DSU(int _v) {
    m_v = _v;
    m_parent.resize(m_v);
    m_rank.resize(m_v);
    iota(begin(m_parent), end(m_parent), 0);
    fill(begin(m_rank), end(m_rank), 1);
  }
  int find(int val);
  bool unite(int v1, int v2);

private:
  int m_v;
  vector<int> m_rank;
  vector<int> m_parent;
};

int DSU::find(int val) {
  if (m_parent[val] == val) {
    return val;
  }
  return m_parent[val] = find(m_parent[val]);
}

bool DSU::unite(int v1, int v2) {
  int p1 = find(v1);
  int p2 = find(v2);
  if (p1 == p2) {
    return false;
  }
  if (m_rank[p1] < m_rank[p2]) {
    swap(p1, p2);
  }
  m_parent[p2] = p1;
  m_rank[p1] += m_rank[p2];
  return true;
}

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    DSU dsu(edges.size());
    for (const auto &edge : edges) {
      if (!dsu.unite(edge[0] - 1, edge[1] - 1)) {
        return edge;
      }
    }
    return {};
  }
};
