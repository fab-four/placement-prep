/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/
 */

vector<vector<int>> Solution::solve(int k, vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp = matrix;

    for (int dist = 0; dist < k; dist++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int curr = matrix[r][c];
                int top = (r == 0 ? -1 : matrix[r - 1][c]);
                int bottom = (r == rows - 1 ? -1 : matrix[r + 1][c]);
                int left = (c == 0 ? -1 : matrix[r][c - 1]);
                int right = (c == cols - 1 ? -1 : matrix[r][c + 1]);

                dp[r][c] = max({curr, top, left, bottom, right});
            }
        }
        matrix = dp;
    }
    return matrix;
}