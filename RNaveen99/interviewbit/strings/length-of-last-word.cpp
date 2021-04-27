/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/length-of-last-word/
 */

int Solution::lengthOfLastWord(const string A) {
    int n = A.length();
    if (n == 0)
        return 0;

    int i = n - 1;
    while (i >= 0 && A[i] == ' ')
        i--;

    int count = 0;
    while (i >= 0 && A[i] != ' ') {
        count++;
        i--;
    }

    return count;
}