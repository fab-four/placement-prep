/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/cycle-in-undirected-graph/
 */

bool dfs(vector<int> adj[], vector<bool> &visited, int vertex, int parent) {
    visited[vertex] = true;
    for (const auto &v : adj[vertex]) {
        if (visited[v] == false) {
            if (dfs(adj, visited, v, vertex)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int Solution::solve(int nodes, vector<vector<int>> &edges) {
    vector<int> adj[nodes];
    vector<bool> visited(nodes, false);
    for (const auto &edge : edges) {
        adj[edge[0] - 1].push_back(edge[1] - 1);
        adj[edge[1] - 1].push_back(edge[0] - 1);
    }
    for (int i = 0; i < nodes; i++) {
        if (!visited[i] && dfs(adj, visited, i, -1)) {
            return 1;
        }
    }
    return 0;
}