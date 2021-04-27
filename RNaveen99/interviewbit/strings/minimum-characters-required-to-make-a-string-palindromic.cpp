/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
 */

/*Idea is to find longest palindrome length starting from index 0.
Difference of this length from string length is the required value */

int Solution::solve(string A) {
    int start = 0, end = A.length() - 1;
    int temp_end = end;

    while (start <= temp_end) {
        if (A[start] == A[temp_end]) {
            start++;
            temp_end--;
        } else {
            start = 0;
            end--;
            temp_end = end;
        }
    }

    return A.length() - (end + 1);
}

bool ispalindrome(string &s, int j) {
    for (int i = 0; i <= j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

int Solution::solve(string s) {
    int count = 0;
    int size = s.length() - 1;
    while (s.length() > 0) {
        if (ispalindrome(s, size))
            break;
        else {
            size--;
            count++;
        }
    }
    return count;
}