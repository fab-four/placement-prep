// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int lengthOfLongestSubstring(string s) {
    vector<int> freq(256, -1);
    int i = 0, j = 0;
    int res = 0;
    while (j < s.size()) {
      if (freq[s[j]] != -1) {
        i = max(i, freq[s[j]] + 1);
      }
      freq[s[j]] = j;
      res = max(res, j - i + 1);
      j++;
    }
    return res;
  }
};
