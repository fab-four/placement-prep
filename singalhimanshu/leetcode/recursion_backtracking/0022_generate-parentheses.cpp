// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    rec(n, n, "", res);
    return res;
  }

  void rec(int open, int close, string s, vector<string> &res) {
    if (open == 0 && close == 0) {
      res.push_back(s);
      return;
    }
    if (open > 0) {
      rec(open - 1, close, s + "(", res);
    }
    if (close > open) {
      rec(open, close - 1, s + ")", res);
    }
  }
};
