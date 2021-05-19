/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/snake-ladder-problem/
 */

int snakesAndLadders(vector<int> &arr) {
    // n = 101
    int n = arr.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int u = curr.first;
        int d = curr.second;
        if (u == n - 1) {
            return d;
        }
        visited[u] = true;
        for (int i = 1; i <= 6; i++) {
            int square = u + i;
            if (square < n && arr[square] != -1) {
                square = arr[square];
            }
            if (square >= n) {
                continue;
            }
            if (visited[square] == false) {
                q.push({square, d + 1});
            }
        }
    }
    return -1;
}

int Solution::snakeLadder(vector<vector<int>> &ladder, vector<vector<int>> &snake) {
    vector<int> board(101, -1);
    for (const auto &edge : ladder) {
        int u = edge[0];
        int v = edge[1];
        board[u] = v;
    }
    for (const auto &edge : snake) {
        int u = edge[0];
        int v = edge[1];
        board[u] = v;
    }
    return snakesAndLadders(board);
}