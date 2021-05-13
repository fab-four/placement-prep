/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/kingdom-war/
 */

// The rows and column are sorted.
// This means, we don't really need to check every single sub-array.
// The largest sub-array strength may start from any point, but will definitely end on bottom-right cell
// (N,M).

int Solution::solve(vector<vector<int>> &A) {
    vector<vector<int>> B = A;
    if (A.size() == 0 || A[0].size() == 0)
        return INT_MIN;
    int r = A.size(), c = A[0].size();
    for (int i = r - 2; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            B[i][j] += B[i + 1][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = c - 2; j >= 0; j--) {
            B[i][j] += B[i][j + 1];
        }
    }
    int max_sum = INT_MIN;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (B[i][j] > max_sum)
                max_sum = B[i][j];
        }
    }
    return max_sum;
}

int Solution::solve(vector<vector<int>> &vec) {
    int row = vec.size();
    int col = vec[0].size();

    int sum = vec[row - 1][col - 1];

    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            if (i < row - 1) {
                vec[i][j] += vec[i + 1][j];
            }
            if (j < col - 1) {
                vec[i][j] += vec[i][j + 1];
            }
            if (i < row - 1 && j < col - 1) {
                vec[i][j] -= vec[i + 1][j + 1];
            }
            sum = max(vec[i][j], sum);
        }
    }

    return sum;
}