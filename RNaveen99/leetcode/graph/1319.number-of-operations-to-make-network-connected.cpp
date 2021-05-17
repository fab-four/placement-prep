/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 */

// DFS
class Solution {
    typedef vector<vector<int>> graph;

  public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        graph g = buildGraph(n, connections);
        vector<bool> visited(n, false);
        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, g, visited);
                connectedComponents++;
            }
        }
        return connectedComponents - 1;
    }

    graph buildGraph(int n, graph &connections) {
        graph g(n);
        for (vector<int> ele : connections) {
            g[ele[0]].push_back(ele[1]);
            g[ele[1]].push_back(ele[0]);
        }
        return g;
    }
    void dfs(int i, graph &g, vector<bool> &visited) {
        visited[i] = true;
        for (int ele : g[i]) {
            if (!visited[ele]) {
                dfs(ele, g, visited);
            }
        }
    }
};

// union-find with path compression
class Solution {
    typedef vector<vector<int>> graph;

  public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        vector<int> parent(n, -1);
        for (vector<int> connection : connections) {
            int parentU = find(connection[0], parent);
            int parentV = find(connection[1], parent);
            if (parentU != parentV) {
                parent[parentU] = parentV;
                n--;
            }
        }
        return n - 1;
    }

    int find(int x, vector<int> &parent) {
        if (parent[x] < 0) {
            return x;
        }
        int temp = find(parent[x], parent);
        parent[x] = temp;
        return temp;
    }
};