/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/redundant-connection-ii/
 */

// Reference :
// https://leetcode.com/problems/redundant-connection-ii/discuss/141897/3ms-Union-Find-with-Explanations

// case 1: two-parent problem such that an error node is with two parents
// eg - [1,2], [1,3], [2,3]
// solution - remove the second parentEdge of the node with two parents

// case 2: cyclic problem such that there is a cycle in the graph
// eg - [1,2], [2,3], [3,1]
// solution - remove the edge that forms the cycle

// case 3: two-parent and cyclic problem
// eg - [1,2], [2,3], [3,1], [4,3]
// solution - remove [2, 3]

class Solution {
    vector<int> parent;

  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int twoParentsEdge = -1;
        int edgeMakesCycle = -1;
        int firstParent;

        parent.resize(edges.size() + 1, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (parent[v] != 0) {
                twoParentsEdge = i;
                firstParent = parent[v];
                break;
            }
            parent[v] = u;
        }

        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < edges.size(); i++) {
            if (i == twoParentsEdge)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if (!canUnion(u, v)) {
                edgeMakesCycle = i;
                break;
            }
        }

        if (edgeMakesCycle != -1 && twoParentsEdge != -1) {
            int u = firstParent;
            int v = edges[twoParentsEdge][1];
            return {u, v};
        }
        if (twoParentsEdge == -1)
            return edges[edgeMakesCycle];
        if (edgeMakesCycle == -1)
            return edges[twoParentsEdge];

        // no Redundant Connection
        return {0, 0};
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    bool canUnion(int u, int v) {
        int rootX = find(u);
        int rootY = find(v);

        if (rootX == rootY) {
            return false;
        }
        parent[rootX] = rootY;
        return true;
    }
};