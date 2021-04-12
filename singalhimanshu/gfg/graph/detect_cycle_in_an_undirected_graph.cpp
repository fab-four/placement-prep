// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

class Solution {
public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
      if (!vis[i] && dfs(i, adj, vis, -1)) {
        return true;
      }
    }
    return false;
  }

  bool dfs(int src, vector<int> adj[], vector<bool> &vis, int parent) {
    vis[src] = true;
    for (const auto &neigh : adj[src]) {
      if (vis[neigh] && neigh != parent) {
        return true;
      }
      if (!vis[neigh] && dfs(neigh, adj, vis, src)) {
        return true;
      }
    }
    return false;
  }
};
