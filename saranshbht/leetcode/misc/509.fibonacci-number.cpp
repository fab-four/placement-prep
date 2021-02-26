/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/fibonacci-number/
 */

class Solution {
public:
  int fib(int n) {
    // Dynamic Programmming
    // if (n <= 1)
    //   return n;

    // vector<int> f(n + 1);
    // f[0] = 0, f[1] = 1;
    // for (int i = 2; i <= n; i++)
    //   f[i] = f[i - 1] + f[i - 2];
    // return f[n];

    // Recursive
    // if (n <= 1)
    //   return n;

    // return fib(n - 1) + fib(n - 2);

    // Iterative
    if (n <= 1)
      return n;
    int res = 0;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
      res = a + b;
      a = b;
      b = res;
    }
    return res;
  }
};