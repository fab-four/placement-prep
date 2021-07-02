/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/path-with-minimum-effort/
 */

// Dijkstra
typedef pair<int, pair<int, int>> pr;
class Solution {
  public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<int> directions = {-1, 0, 1, 0, -1};

        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.emplace(0, make_pair(0, 0));

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int effort = top.first;
            int r = top.second.first;
            int c = top.second.second;
            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }
            if (effort >= efforts[r][c]) {
                continue;
            }
            efforts[r][c] = effort;

            for (int i = 0; i < 4; i++) {
                int x = r + directions[i];
                int y = c + directions[i + 1];
                if (x < 0 || x == rows || y < 0 || y == cols) {
                    continue;
                }
                int nextEffort = max(efforts[r][c], abs(heights[r][c] - heights[x][y]));
                pq.emplace(nextEffort, make_pair(x, y));
            }
        }
        return -1;
    }
};