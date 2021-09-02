/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/critical-connections-in-a-network/
 */

class Solution {
    vector<vector<int>> graph;
    vector<int> ranks;
    vector<vector<int>> result;

  public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        graph.resize(n);
        for (auto &conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        ranks.resize(n, -1);

        dfs(0, 1);
        return result;
    }

    int dfs(int node, int rank) {
        if (ranks[node] >= 0)
            return ranks[node];

        ranks[node] = rank;
        int minRank = rank;

        for (auto neighbor : graph[node]) {
            // neighbor is parent
            if (ranks[neighbor] == rank - 1)
                continue;

            // forward edge in undirected graph is already processed
            if (ranks[neighbor] > rank)
                continue;

            int neighborRank = dfs(neighbor, rank + 1);
            minRank = min(minRank, neighborRank);
            if (neighborRank > rank) {
                result.push_back({node, neighbor});
            }
        }
        return minRank;
    }
};