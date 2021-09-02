/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/cut-off-trees-for-golf-event/
 */

class Solution {
    typedef pair<int, int> PI;
    vector<int> dir = {0, 1, 0, -1, 0};

  public:
    int cutOffTree(vector<vector<int>> &forest) {
        int rows = forest.size();
        int cols = forest[0].size();

        priority_queue<pair<int, PI>, vector<pair<int, PI>>, greater<>> pq;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (forest[r][c] > 1) {
                    pq.push({forest[r][c], {r, c}});
                }
            }
        }
        int startRow = 0;
        int startCol = 0;
        int sum = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int destinationRow = top.second.first;
            int destinationCol = top.second.second;

            int steps = minSteps(forest, startRow, startCol, destinationRow, destinationCol, rows, cols);

            if (steps < 0)
                return -1;
            sum += steps;
            startRow = destinationRow;
            startCol = destinationCol;
        }

        return sum;
    }

    int minSteps(vector<vector<int>> &forest, const int &startRow, const int &startCol,
                 const int &destinationRow, const int &destinationCol, const int &rows, const int &cols) {

        int steps = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.emplace(startRow, startCol);

        visited[startRow][startCol] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                if (r == destinationRow && c == destinationCol)
                    return steps;

                for (int i = 0; i + 1 < dir.size(); i++) {
                    int x = r + dir[i];
                    int y = c + dir[i + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y] && forest[x][y]) {
                        q.emplace(x, y);
                        visited[x][y] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};