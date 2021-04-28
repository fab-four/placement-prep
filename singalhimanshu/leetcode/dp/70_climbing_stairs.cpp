// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int climbStairs(int n) {
    int one_back = 1;
    int two_back = 1;
    for (int i = 2; i < n + 1; i++) {
      int temp = one_back;
      one_back += two_back;
      two_back = temp;
    }
    return one_back;
  }
};
