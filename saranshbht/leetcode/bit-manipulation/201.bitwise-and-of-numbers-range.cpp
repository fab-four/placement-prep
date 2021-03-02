/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    while (m != n) {
      shift++;
      m >>= 1;
      n >>= 1;
    }
    return m << shift;
  }
};