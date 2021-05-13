/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/maximum-path-in-triangle/
 */

int Solution::solve(vector<vector<int>> &A) {
    int rows = A.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int j = 0; j < rows; j++) {
        dp[rows - 1][j] = A[rows - 1][j];
    }
    for (int i = rows - 2; i >= 0; i--) {
        for (int j = 0; j < rows - 1; j++) {
            dp[i][j] = A[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}