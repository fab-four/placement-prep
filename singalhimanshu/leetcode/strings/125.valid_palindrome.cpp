// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  bool isPalindrome(string s) {
    string temp;
    for (char c : s) {
      if (isalnum(c)) {
        temp.push_back(tolower(c));
      }
    }
    s = move(temp);
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
};
