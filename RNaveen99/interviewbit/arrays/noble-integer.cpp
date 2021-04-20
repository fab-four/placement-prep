/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/noble-integer/
 */

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1])
            continue;
        if (A[i] == n - i - 1)
            return 1;
    }
    if (A[n - 1] == 0)
        return 1;
    return -1;
}