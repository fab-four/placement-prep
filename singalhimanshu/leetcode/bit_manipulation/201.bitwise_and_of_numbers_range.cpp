// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
  // Time Complexity : O(log(n))
  // Space Complexity : O(1)
  int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      shift++;
    }
    return left << shift;
  }
};
