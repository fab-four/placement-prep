// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  string minWindow(string s, string t) {
    vector<int> freq(128, 0);
    for (char c : t) {
      freq[c]++;
    }
    int i = 0, j = 0;
    int count = t.size(), min_start = 0, min_len = INT_MAX;
    while (j < s.size()) {
      if (freq[s[j]] > 0) {
        count--;
      }
      freq[s[j]]--;
      j++;
      while (count == 0) {
        if (j - i < min_len) {
          min_start = i;
          min_len = j - i;
        }
        freq[s[i]]++;
        if (freq[s[i]] > 0) {
          count++;
        }
        i++;
      }
    }
    if (min_len != INT_MAX) {
      return s.substr(min_start, min_len);
    }
    return "";
  }
};
