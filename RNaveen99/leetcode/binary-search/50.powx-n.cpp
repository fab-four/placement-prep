/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/powx-n/
 */

class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            if (n == INT_MIN) {
                n += 2;
            }
            n = -n;
            x = 1 / x;
        }
        double temp = myPow(x, n / 2);

        if (n & 1) {
            return x * temp * temp;
        } else {
            return temp * temp;
        }
    }
};

class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            if (n == INT_MIN) {
                n += 2;
            }
            n = -n;
            x = 1 / x;
        }
        if (n & 1) {
            return x * myPow(x * x, n / 2);
        } else {
            return myPow(x * x, n / 2);
        }
    }
};

class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            if (n == INT_MIN) {
                n += 2;
            }
            n = -n;
            x = 1 / x;
        }
        double result = 1;
        while (n) {
            if (n & 1) {
                result = result * x;
            }
            x = x * x;
            n = n >> 1;
        }
        return result;
    }
};