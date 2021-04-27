// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/power-of-three/

class Solution {
public:
  // Time Complexity : O(1)
  // Space Complexity : O(1)
  bool isPowerOfThree(int n) {
    return fmod(log10(n) / log10(3), 1) == 0;
    // return loop(n);
  }

  // Time Complexity : O(log3(n))
  // Space Complexity : O(1)
  bool loop(int n) {
    if (n == 0) {
      return false;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }
};
