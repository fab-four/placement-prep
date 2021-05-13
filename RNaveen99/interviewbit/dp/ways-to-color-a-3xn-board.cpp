/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
 */

// Each column has 3 cells.
// we have 4 colours ... A, B, C and D.
// We can colour a column with 3 colours + We can colour a column with 2 colours.
// => 4C3 * 3! + 4C2 * 2
// => 4 * 6 + 6 * 2 = 24 + 12 = 36 ways

// Reference Link : https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/

int Solution::solve(int A) {
    long int color3 = 24;
    long int color2 = 12;
    long int temp = 0;
    for (int i = 2; i <= A; i++) {
        temp = color3;
        color3 = (11 * color3 + 10 * color2) % 1000000007;
        color2 = (5 * temp + 7 * color2) % 1000000007;
    }
    return (color3 + color2) % 1000000007;
}