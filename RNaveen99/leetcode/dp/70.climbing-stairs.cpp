/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/climbing-stairs/
 */

class Solution {
  public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        vector<int> stairs(n, 0);
        stairs[n - 1] = 1;
        stairs[n - 2] = 2;

        for (int i = n - 3; i >= 0; i--) {
            stairs[i] = stairs[i + 1] + stairs[i + 2];
        }
        return stairs[0];
    }
};

class Solution {
  public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        int first = 1;
        int second = 2;

        int third;
        for (int i = 3; i <= n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};