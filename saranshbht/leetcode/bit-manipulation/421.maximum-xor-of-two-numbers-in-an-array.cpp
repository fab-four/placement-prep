/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   :
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 */

class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int mask = 0, res = 0;
    for (int i = 31; i >= 0; i--) {
      // mask will be 1000..., 1100..., 11100... in successive iterations
      mask |= (1 << i);

      unordered_set<int> s;
      // add those numbers to set that have some of the leftmost 32 - i bits set
      for (auto &i : nums) {
        s.insert(i & mask);
      }

      // check if (i + 1)th LSB of res can be set
      int temp = (res | (1 << i));
      for (auto &i : s) {
        if (s.count(i ^ temp)) {
          res = temp;
          break;
        }
      }
    }
    return res;
  }
};