/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-height-trees/
 */

// BFS, Topological Sort
// keep deleting leaves layer-by-layer, until reach the root.
class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degrees(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1]);
            adj[edges[i][1]].emplace_back(edges[i][0]);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            // adding all the leave nodes
            if (degrees[i] == 1) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            result.clear();
            int size = q.size();
            while (size--) {
                int front = q.front();
                q.pop();
                result.emplace_back(front);
                for (auto &neighbor : adj[front]) {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) {
                        q.emplace(neighbor);
                    }
                }
            }
        }
        return result;
    }
};