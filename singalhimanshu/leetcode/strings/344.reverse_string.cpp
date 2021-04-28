// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/reverse-string/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  void reverseString(vector<char> &s) {
    for (int i = 0; i < s.size() / 2; i++) {
      swap(s[i], s[s.size() - i - 1]);
    }
  }
};
