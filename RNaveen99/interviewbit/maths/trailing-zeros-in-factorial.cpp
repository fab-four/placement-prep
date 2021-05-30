/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
 */

int Solution::trailingZeroes(int A) {
    int ans = 0;
    while (A >= 5) {
        ans += (A / 5);
        A /= 5;
    }
    return ans;
}