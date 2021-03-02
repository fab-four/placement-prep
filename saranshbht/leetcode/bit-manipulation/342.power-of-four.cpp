/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/power-of-four/
 */

class Solution {
public:
  bool isPowerOfFour(int n) {
    // n should be positive
    // n should be a power of 2
    // n should have its only set bit at odd position
    return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) == n);
  }
};