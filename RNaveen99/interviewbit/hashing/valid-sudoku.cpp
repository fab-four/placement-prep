/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/valid-sudoku/
 */

int Solution::isValidSudoku(const vector<string> &A) {
    vector<vector<bool>> rowTracker(9, vector<bool>(9, false));
    vector<vector<bool>> colTracker(9, vector<bool>(9, false));
    vector<vector<bool>> boxTracker(9, vector<bool>(9, false));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (A[i][j] == '.')
                continue;

            int d = A[i][j] - '1';
            int box = (i / 3) * 3 + (j / 3);

            if (rowTracker[i][d] || colTracker[j][d] || boxTracker[box][d]) {
                return 0;
            }

            rowTracker[i][d] = colTracker[j][d] = boxTracker[box][d] = true;
        }
    }
    return 1;
}