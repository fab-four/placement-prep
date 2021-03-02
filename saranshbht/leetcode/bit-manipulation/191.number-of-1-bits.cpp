/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/number-of-1-bits/
 */

class Solution {
public:
  int hammingWeight(uint32_t n) {
    // first
    // int cnt = 0;
    // while (n) {
    //     cnt += (n & 1);
    //     n >>= 1;
    // }
    // return cnt;

    // second (better)
    int cnt = 0;
    while (n) {
      cnt++;
      n &= n - 1;
    }
    return cnt;
  }
};