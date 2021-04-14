// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/topological-sort/1#

class Solution {
public:
  vector<int> topoSort(int V, vector<int> adj[]) {
    return bfsTopo(V, adj);
    // return dfsTopo(V, adj);
  }

  // Kahn's Algorithm
  vector<int> bfsTopo(int V, const vector<int> adj[]) {
    vector<int> indegree(V);
    fillIndegree(indegree, V, adj);
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> topo;
    while (!q.empty()) {
      int cur = q.front();
      topo.emplace_back(cur);
      q.pop();
      for (const auto &neigh : adj[cur]) {
        indegree[neigh]--;
        if (indegree[neigh] == 0) {
          q.push(neigh);
        }
      }
    }
    return topo;
  }

  void fillIndegree(vector<int> &indegree, int v, const vector<int> adj[]) {
    for (int i = 0; i < v; i++) {
      for (const auto &neigh : adj[i]) {
        indegree[neigh]++;
      }
    }
  }

  vector<int> dfsTopo(int V, const vector<int> adj[]) {
    stack<int> topo;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(i, adj, topo, vis);
      }
    }
    vector<int> result;
    result.reserve(topo.size());
    while (!topo.empty()) {
      result.emplace_back(topo.top());
      topo.pop();
    }
    return result;
  }

  void dfs(int src, const vector<int> adj[], stack<int> &topo,
           vector<bool> &vis) {
    vis[src] = true;
    for (const auto &neigh : adj[src]) {
      if (!vis[neigh]) {
        dfs(neigh, adj, topo, vis);
      }
    }
    topo.push(src);
  }
};
