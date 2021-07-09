/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/is-graph-bipartite/
 */

class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == 0 && !canColor(graph, color, i, 1)) {
                return false;
            }
        }
        return true;
    }
    bool canColor(vector<vector<int>> &graph, vector<int> &color, int i, int nodeColor) {

        color[i] = nodeColor;
        for (int j = 0; j < graph[i].size(); j++) {
            // same color
            if (color[graph[i][j]] == nodeColor) {
                return false;
            }
            // different color
            if (color[graph[i][j]] == -nodeColor) {
                continue;
            } else if (!canColor(graph, color, graph[i][j], -nodeColor)) {
                return false;
            }
        }
        return true;
    }
};