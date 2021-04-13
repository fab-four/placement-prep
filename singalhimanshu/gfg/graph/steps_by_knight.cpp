// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/steps-by-knight/0

struct Point {
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
  int minStepToReachTarget(vector<int> &knight_pos, vector<int> &target_pos,
                           int N) {
    knight_pos[0]--;
    knight_pos[1]--;
    target_pos[0]--;
    target_pos[1]--;
    return bfs(knight_pos, target_pos, N);
  }

  int bfs(const vector<int> &knight_pos, const vector<int> &target_pos, int n) {
    int moves = 0;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    array<int, 8> dx = {2, 2, -2, -2, 1, -1, 1, -1};
    array<int, 8> dy = {1, -1, 1, -1, 2, 2, -2, -2};
    queue<Point> q;
    q.push(Point(knight_pos[0], knight_pos[1]));
    vis[knight_pos[0]][knight_pos[1]] = true;
    while (!q.empty()) {
      size_t q_size = q.size();
      for (size_t i = 0; i < q_size; i++) {
        Point cur = q.front();
        q.pop();
        for (size_t i = 0; i < dx.size(); i++) {
          int new_x = cur.x + dx[i];
          int new_y = cur.y + dy[i];
          if ((new_x == target_pos[0]) && (new_y == target_pos[1])) {
            return moves + 1;
          }
          if (!isOutOfBounds(new_x, new_y, n) && !vis[new_x][new_y]) {
            vis[new_x][new_y] = true;
            q.push(Point(new_x, new_y));
          }
        }
      }
      moves++;
    }
    return 0;
  }

  bool isOutOfBounds(int row, int col, int n) {
    return (row < 0) || (col < 0) || (row >= n) || (col >= n);
  }
};
