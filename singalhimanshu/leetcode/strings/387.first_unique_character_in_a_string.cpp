// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int firstUniqChar(string s) {
    vector<int> freq(256, -1);
    for (int i = 0; i < s.size(); i++) {
      if (freq[s[i]] == -1) {
        freq[s[i]] = i;
      } else {
        freq[s[i]] = -2;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (freq[s[i]] >= 0) {
        return freq[s[i]];
      }
    }
    return -1;
  }
};
