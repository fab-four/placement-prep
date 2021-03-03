/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/integer-replacement/
 */

class Solution {
public:
  int integerReplacement(int n) {
    if (n < 4)
      return n - 1;
    int res = 0;
    uint32_t num = n;
    while (num > 1) {
      if (num & 1) {
        if ((num != 3) && (num & 3) == 3)
          num++;
        else
          num--;
      } else {
        num >>= 1;
      }
      res++;
    }
    return res;
  }
};