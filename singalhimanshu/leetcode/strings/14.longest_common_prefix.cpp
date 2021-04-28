// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
  // Time Complexity : O(n * min_str_size)
  // Space Complexity : O(1)
  string longestCommonPrefix(vector<string> &strs) {
    size_t min_size = INT_MAX;
    for (const string &str : strs) {
      min_size = min(min_size, str.size());
    }
    int ans = 0;
    int n = strs.size();
    bool flag = false;
    for (int i = 0; i < min_size; i++) {
      char cmp = strs[0][i];
      for (int j = 0; j < n; j++) {
        if (strs[j][i] != cmp) {
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
      ans++;
    }
    return strs[0].substr(0, ans);
  }
};
