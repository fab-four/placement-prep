/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/chain-of-pairs/
 */

int Solution::solve(vector<vector<int>> &A) {
    int N = A.size();
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int b = A[j][1];
            int c = A[i][0];
            if (b < c) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}