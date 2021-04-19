/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/anti-diagonals/
 */

vector<vector<int>> Solution::diagonal(vector<vector<int>> &A) {
    vector<vector<int>> result;
    vector<int> diagonal;

    int size = A.size();
    if (size == 0)
        return result;
    for (int d = 0; d <= 2 * (size - 1); d++) {
        for (int row = 0, col = d; row <= d && row < size; row++, col--) {
            if (col >= size)
                continue;
            diagonal.push_back(A[row][col]);
        }
        result.push_back(diagonal);
        diagonal.clear();
    }
    return result;
}

vector<vector<int>> Solution::diagonal(vector<vector<int>> &A) {
    int n = A.size();
    // number of anti diagonals
    int N = (2 * n) - 1;
    vector<vector<int>> ans(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            // sum of index values in 2d array gives the index in ans
            ans[i + j].push_back(A[i][j]);
    }
    return ans;
}
