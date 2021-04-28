// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  bool isAnagram(string s, string t) {
    vector<int> freq(256, 0);
    for (char c : s) {
      freq[c]++;
    }
    for (char c : t) {
      freq[c]--;
    }
    for (int it : freq) {
      if (it != 0) {
        return false;
      }
    }
    return true;
  }
};
