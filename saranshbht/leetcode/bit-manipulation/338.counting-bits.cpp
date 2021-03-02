/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/counting-bits/
 */

class Solution {
public:
  vector<int> countBits(int num) {
    // mask = greatest power of 2 less than equal to i
    int mask = 1;
    vector<int> res(num + 1, 0);
    for (int i = 1; i < num + 1; i++) {
      if ((mask << 1) == i)
        mask <<= 1;
      res[i] = res[i - (mask & i)] + 1;
    }
    return res;
  }
};