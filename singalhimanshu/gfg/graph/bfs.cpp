// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

class Solution {
public:
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
      int top = q.front();
      result.emplace_back(top);
      q.pop();
      for (const auto &neigh : adj[top]) {
        if (!vis[neigh]) {
          vis[neigh] = true;
          q.push(neigh);
        }
      }
    }
    return result;
  }
};
