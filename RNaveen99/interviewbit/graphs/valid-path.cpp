/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/valid-path/
 */

bool isInsideCircle(int x, int y, int ri, int rj, int r) {
    return pow(x - ri, 2) + pow(y - rj, 2) <= pow(r, 2);
}

bool checkInsideCircle(int x, int y, vector<int> &X, vector<int> &Y, int R) {
    for (int i = 0; i < X.size(); i++) {
        if (isInsideCircle(x, y, X[i], Y[i], R)) {
            return true;
        }
    }
    return false;
}

bool isValid(int i, int j, int n, int m) { return i >= 0 && j >= 0 && i <= n && j <= m; }

string Solution::solve(int x, int y, int N, int R, vector<int> &X, vector<int> &Y) {
    vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (checkInsideCircle(i, j, X, Y, R)) {
                visited[i][j] = true;
            }
        }
    }
    if (visited[0][0] == 1 || visited[x][y] == 1)
        return "NO";
    queue<pair<int, int>> q;
    q.insert({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a == x && b == y) {
            return "YES";
        }
        for (int i = 0; i < 8; i++) {
            int newX = a + dx[i];
            int newY = b + dy[i];
            if (isValid(newX, newY, x, y) && !visited[newX][newY]) {
                q.insert({newX, newY});
                visited[newX][newY] = 1;
            }
        }
    }
    return "NO";
}