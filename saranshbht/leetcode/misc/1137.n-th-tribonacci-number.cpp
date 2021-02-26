/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/n-th-tribonacci-number/
 */

class Solution {
public:
  int tribonacci(int n) {
    // Dynamic Programming
    // if (n == 0)
    //   return 0;
    // else if (n == 1 || n == 2)
    //   return 1;

    // vector<int> trib(n + 1);
    // trib[0] = 0;
    // trib[1] = trib[2] = 1;
    // for (int i = 3; i <= n; i++)
    //   trib[i] = trib[i - 1] + trib[i - 2] + trib[i - 3];
    // return trib[n];

    // Iterative
    if (n == 0)
      return 0;
    else if (n == 1 || n == 2)
      return 1;

    int a = 0, b = 1, c = 1;
    int res;
    for (int i = 3; i <= n; i++) {
      res = a + b + c;
      a = b;
      b = c;
      c = res;
    }
    return res;
  }
};