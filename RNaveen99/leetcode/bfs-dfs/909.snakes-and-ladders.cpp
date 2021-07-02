/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/snakes-and-ladders/
 */

class Solution {
  public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        int size = rows * cols;
        vector<int> arr(size + 1, 1);
        int r = rows - 1, c = 0, index = 1, inc = 1;
        while (index <= size) {
            arr[index++] = board[r][c];
            if (inc == 1 && c == cols - 1) {
                inc = -1;
                r--;
            } else if (inc == -1 && c == 0) {
                inc = 1;
                r--;
            } else {
                c += inc;
            }
        }
        vector<bool> visited(size + 1, false);
        queue<int> q;
        int start = arr[1] > -1 ? arr[1] : 1;
        q.emplace(start);
        visited[start] = true;
        int step = 0;
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize) {
                qSize--;
                int front = q.front();
                q.pop();
                if (front == size) {
                    return step;
                }

                for (int next = front + 1; next <= min(front + 6, size); next++) {
                    int dest = arr[next] > -1 ? arr[next] : next;
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.emplace(dest);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

class Solution {
  public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        int size = rows * cols;
        vector<bool> visited(size + 1, false);
        queue<int> q;
        int value = getBoardValue(board, 1);
        if (value == -1) {
            value = 1;
        }
        q.emplace(value);
        visited[value] = true;
        int step = 0;
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize) {
                qSize--;
                int front = q.front();
                q.pop();
                if (front == size) {
                    return step;
                }

                for (int next = front + 1; next <= min(front + 6, size); next++) {
                    int dest = getBoardValue(board, next);
                    if (dest == -1) {
                        dest = next;
                    }
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.emplace(dest);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    int getBoardValue(vector<vector<int>> &board, int num) {
        int rows = board.size();
        int r = (num - 1) / rows;
        int c = (num - 1) % rows;

        int x = rows - 1 - r;
        int y = r % 2 == 1 ? rows - 1 - c : c;

        return board[x][y];
    }
};