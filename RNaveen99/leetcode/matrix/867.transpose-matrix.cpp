/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/transpose-matrix/
 */

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        vector<vector<int>> results(matrix[0].size(), vector<int>(matrix.size(), 0));

        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < results[0].size(); j++) {
                results[i][j] = matrix[j][i];
            }
        }
        return results;
    }
};