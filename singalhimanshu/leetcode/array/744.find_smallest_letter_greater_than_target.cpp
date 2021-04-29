// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
  // Time Complexity : O(log(n))
  // Space Complexity : O(1)
  char nextGreatestLetter(vector<char> &letters, char target) {
    char res = ' ';
    int l = 0, r = letters.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (letters[mid] > target) {
        res = letters[mid];
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    res = res == ' ' ? letters.front() : res;
    return res;
  }
};
