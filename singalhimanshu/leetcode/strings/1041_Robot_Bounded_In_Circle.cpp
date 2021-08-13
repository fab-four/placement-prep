class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  bool isRobotBounded(string instructions) {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0;
    int pos = 0;
    for (char c : instructions) {
      if (c == 'R') {
        pos = (pos + 1) % 4;
      } else if (c == 'L') {
        pos = (pos + 3) % 4;
      } else {
        x += dir[pos][0];
        y += dir[pos][1];
      }
    }
    return x == 0 && y == 0 || pos > 0;
  }
};
