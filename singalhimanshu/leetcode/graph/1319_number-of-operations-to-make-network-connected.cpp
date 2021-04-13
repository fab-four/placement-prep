// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1) {
      return -1;
    }
    auto adj_list = getAdjList(n, connections);
    int components_count = countComp(n, adj_list);
    return components_count - 1;
  }

  vector<vector<int>> getAdjList(int n,
                                 const vector<vector<int>> &connections) {
    vector<vector<int>> adj_list(n);
    for (const auto &connection : connections) {
      adj_list[connection[0]].emplace_back(connection[1]);
      adj_list[connection[1]].emplace_back(connection[0]);
    }
    return adj_list;
  }

  int countComp(int n, const vector<vector<int>> &adj_list) {
    vector<bool> vis(n, false);
    int components_count = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(i, adj_list, vis);
        components_count++;
      }
    }
    return components_count;
  }

  void dfs(int src, const vector<vector<int>> &adj_list, vector<bool> &vis) {
    vis[src] = true;
    for (const auto &neigh : adj_list[src]) {
      if (!vis[neigh]) {
        dfs(neigh, adj_list, vis);
      }
    }
  }
};
