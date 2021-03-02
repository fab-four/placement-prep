/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/single-number-iii/
 */

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    unsigned int xor_res = 0;
    for (int &i : nums)
      xor_res ^= i;
    xor_res &= -xor_res;

    int xor_set = 0, xor_not_set = 0;
    for (int &i : nums) {
      if (i & xor_res)
        xor_set ^= i;
      else
        xor_not_set ^= i;
    }
    return {xor_set, xor_not_set};
  }
};