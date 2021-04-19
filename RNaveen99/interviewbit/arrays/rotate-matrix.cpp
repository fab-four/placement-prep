/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/rotate-matrix/
 */

// approach - transpose & reverse each row OR reverse each column and transpose

void Solution::rotate(vector<vector<int>> &matrix) {
    // transpose
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[i].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < matrix.size(); ++i) {
        int j = 0;
        int k = matrix[i].size() - 1;
        while (j < k) {
            swap(matrix[i][j], matrix[i][k]);
            j++;
            k--;
        }
    }
}

// Note that if you create a graph with each cell as vertex with an edge from source cell to the
// destination cell, the graph ends up with cycles of length n.
void Solution::rotate(vector<vector<int>> &matrix) {
    int len = matrix.size();
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[len - j - 1][i];
            matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
            matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
            matrix[j][len - i - 1] = tmp;
        }
    }
}