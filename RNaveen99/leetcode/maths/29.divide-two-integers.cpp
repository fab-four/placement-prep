/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/divide-two-integers/
 */

class Solution {
  public:
    int divide(long dividend, long divisor) {
        int sign = (dividend < 0) ^ (divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        long candidate = 0;
        long ONE = 1;
        for (int i = 31; i >= 0; i--) {
            if ((divisor << i) <= dividend) {
                dividend = dividend - (divisor << i);
                candidate = candidate | (ONE << i);
            }
        }

        if (sign) {
            candidate = -candidate;
        }

        return (candidate < INT_MIN || candidate > INT_MAX) ? INT_MAX : candidate;
    }
};