/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/min-sum-path-in-matrix/
 */

int Solution::minPathSum(vector<vector<int>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    dp[0][0] = board[0][0];

    // cumulative sum of column 0(index)
    for (int i = 1; i < rows; i++) {
        dp[i][0] = board[i][0] + dp[i - 1][0];
    }

    // cumulative sum of row 0(index)
    for (int j = 1; j < cols; j++) {
        dp[0][j] = board[0][j] + dp[0][j - 1];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = board[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[rows - 1][cols - 1];
}