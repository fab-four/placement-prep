/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/single-number/
 */

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int num = 0;
    for (auto &i : nums)
      num ^= i;
    return num;
  }
};