#pragma once

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class DSU {
public:
  DSU(size_t _n);

  int find(int val);
  bool unite(int ele1, int ele2);

private:
  size_t m_n;
  vector<int> m_parent;
  vector<int> m_rank;
};

DSU::DSU(size_t _n) {
  m_n = _n;
  m_parent.resize(m_n);
  m_rank.resize(m_n);
  iota(begin(m_parent), end(m_parent), 0);
  fill(begin(m_rank), end(m_rank), 1);
}
int DSU::find(int val) {
  if (m_parent[val] == val) {
    return val;
  }
  return m_parent[val] = find(m_parent[val]);
}

bool DSU::unite(int ele1, int ele2) {
  int parent_1 = find(ele1);
  int parent_2 = find(ele2);
  if (parent_1 == parent_2) {
    return false;
  }
  if (m_rank[parent_1] < m_rank[parent_2]) {
    swap(parent_1, parent_2);
  }
  m_parent[parent_2] = parent_1;
  m_rank[parent_1] += m_rank[parent_2];
  return true;
}
