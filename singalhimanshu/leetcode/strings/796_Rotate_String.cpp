// Link: https://leetcode.com/problems/rotate-string/
class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    if (s == goal) {
      return true;
    }
    int n = goal.size();
    while (n--) {
      if (s == goal) {
        return true;
      }
      s = s.substr(1) + s[0];
    }
    return false;
  }
};
