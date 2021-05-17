/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/redundant-connection/
 */

// Aim: To remove the edge that creates cycle

// union-find with path compression
class Solution {
    vector<int> parent;

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int size = edges.size();
        parent = vector<int>(size + 1, -1);

        for (vector<int> e : edges) {
            if (detectCycle(e[0], e[1])) {
                return e;
            }
        }
        return {};
    }
    int find(int x) {
        if (parent[x] < 0) {
            return x;
        }
        int p = find(parent[x]);
        parent[x] = p;
        return p;
    }
    bool detectCycle(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV) {
            return true;
        }

        parent[parentV] = parentU;
        return false;
    }
};

// DFS
class Solution {
    vector<int> parent;

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int size = edges.size();
        vector<vector<int>> graph(size + 1);

        for (vector<int> e : edges) {
            vector<bool> visited(size + 1, false);
            if (dfs(e[0], e[1], graph, visited)) {
                return e;
            }
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        return {};
    }
    bool dfs(int s, int d, vector<vector<int>> &graph, vector<bool> &visited) {
        if (s == d) {
            return true;
        }
        visited[s] = true;
        for (int e : graph[s]) {
            if (!visited[e]) {
                if (dfs(e, d, graph, visited))
                    return true;
            }
        }
        return false;
    }
};

// BFS
class Solution {
    vector<int> parent;

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int size = edges.size();
        vector<vector<int>> graph(size + 1);

        for (vector<int> e : edges) {
            vector<bool> visited(size + 1, false);
            if (bfs(e[0], e[1], graph, visited)) {
                return e;
            }
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        return {};
    }
    bool bfs(int s, int d, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            if (front == d) {
                return true;
            }
            for (int e : graph[front]) {
                if (!visited[e]) {
                    q.push(e);
                    visited[e] = true;
                }
            }
        }

        return false;
    }
};