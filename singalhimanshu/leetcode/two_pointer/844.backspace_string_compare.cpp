// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  bool backspaceCompare(string s, string t) {
    int s_ptr = s.size() - 1;
    int t_ptr = t.size() - 1;
    while (true) {
      int back = 0;
      while (s_ptr >= 0 && (back > 0 || s[s_ptr] == '#')) {
        back += s[s_ptr] == '#' ? 1 : -1;
        s_ptr--;
      }
      back = 0;
      while (t_ptr >= 0 && (back > 0 || t[t_ptr] == '#')) {
        back += t[t_ptr] == '#' ? 1 : -1;
        t_ptr--;
      }
      if (s_ptr >= 0 && t_ptr >= 0 && s[s_ptr] == t[t_ptr]) {
        s_ptr--;
        t_ptr--;
      } else {
        break;
      }
    }
    return (s_ptr == -1 && t_ptr == -1);
  }
};
