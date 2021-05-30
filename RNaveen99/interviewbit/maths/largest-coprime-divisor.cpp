/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/largest-coprime-divisor/
 */

int Solution::cpFact(int x, int y) {
    // first we will remove the common factors of x and y from x by finding the greatest common divisor (gcd)
    // of x and y and dividing x with that gcd.
    // x = x / gcd(x, y)
    // we repeat till we get gcd(x, y) = 1.
    // At last, we return a = x
    while (__gcd(x, y) != 1) {
        x = x / __gcd(x, y);
    }
    return x;
}