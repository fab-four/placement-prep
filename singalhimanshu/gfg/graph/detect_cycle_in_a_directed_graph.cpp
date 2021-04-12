// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
public:
  bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<bool> cur_path(V, false);
    for (int i = 0; i < V; i++) {
      if (!vis[i] && dfs(i, adj, vis, cur_path)) {
        return true;
      }
    }
    return false;
  }

  bool dfs(int src, vector<int> adj[], vector<bool> &vis,
           vector<bool> &cur_path) {
    cur_path[src] = true;
    vis[src] = true;
    for (const auto &neigh : adj[src]) {
      if (cur_path[neigh]) {
        return true;
      }
      if (!vis[neigh] && dfs(neigh, adj, vis, cur_path)) {
        return true;
      }
    }
    cur_path[src] = false;
    return false;
  }
};
