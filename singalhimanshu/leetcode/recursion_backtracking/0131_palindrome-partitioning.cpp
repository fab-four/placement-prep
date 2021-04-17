// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    solve(0, temp, res, s);
    return res;
  }

  void solve(int pos, vector<string> &temp, vector<vector<string>> &res,
             string &s) {
    if (pos == s.size()) {
      res.push_back(temp);
      return;
    }
    for (int i = pos; i < s.size(); i++) {
      if (isPalin(s, pos, i)) {
        temp.push_back(s.substr(pos, i - pos + 1));
        solve(i + 1, temp, res, s);
        temp.pop_back();
      }
    }
  }

  bool isPalin(const string &s, int start, int end) {
    while (start <= end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};
