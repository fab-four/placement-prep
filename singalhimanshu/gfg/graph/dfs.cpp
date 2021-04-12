// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
public:
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> vis(V, false);
    dfs(0, adj, result, vis);
    return result;
  }

  void dfs(int cur, const vector<int> adj[], vector<int> &result,
           vector<bool> &vis) {
    vis[cur] = true;
    result.emplace_back(cur);
    for (const auto &neigh : adj[cur]) {
      if (!vis[neigh]) {
        vis[neigh] = true;
        dfs(neigh, adj, result, vis);
      }
    }
  }
};
