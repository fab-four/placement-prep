/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/pacific-atlantic-water-flow/
 */

// DFS
class Solution {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> aVisited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            if (!pVisited[i][0])
                dfs(heights, pVisited, i, 0);
            if (!aVisited[i][cols - 1])
                dfs(heights, aVisited, i, cols - 1);
        }
        for (int i = 0; i < cols; i++) {
            if (!pVisited[0][i])
                dfs(heights, pVisited, 0, i);
            if (!aVisited[rows - 1][i])
                dfs(heights, aVisited, rows - 1, i);
        }
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pVisited[i][j] && aVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c) {
        visited[r][c] = true;
        for (vector<int> d : directions) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || visited[x][y] ||
                heights[x][y] < heights[r][c]) {
                continue;
            }
            dfs(heights, visited, x, y);
        }
    }
};

// BFS
class Solution {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> aVisited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> pQ;
        queue<pair<int, int>> aQ;
        for (int i = 0; i < rows; i++) {
            pQ.push({i, 0});
            aQ.push({i, cols - 1});
            pVisited[i][0] = true;
            aVisited[i][cols - 1] = true;
        }
        for (int i = 0; i < cols; i++) {
            pQ.push({0, i});
            aQ.push({rows - 1, i});
            pVisited[0][i] = true;
            aVisited[rows - 1][i] = true;
        }
        bfs(heights, pVisited, pQ);
        bfs(heights, aVisited, aQ);

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pVisited[i][j] && aVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, queue<pair<int, int>> q) {
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (vector<int> d : directions) {
                int x = r + d[0];
                int y = c + d[1];
                if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || visited[x][y] ||
                    heights[x][y] < heights[r][c]) {
                    continue;
                }
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
};