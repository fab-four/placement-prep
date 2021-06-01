/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/pascals-triangle/
 */

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        if (numRows == 0)
            return pascal;
        pascal[0].emplace_back(1);
        if (numRows == 1)
            return pascal;

        for (int i = 1; i < numRows; i++) {
            int currRow = i;
            pascal[currRow].emplace_back(1);

            for (int j = 0; j + 1 < i; j++) {
                int sum = pascal[currRow - 1][j] + pascal[currRow - 1][j + 1];
                pascal[currRow].emplace_back(sum);
            }
            pascal[currRow].emplace_back(1);
        }
        return pascal;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j > 0 && j < i) {
                    row.push_back(pascal.back()[j-1]+pascal.back()[j]);
                } else {
                    row.push_back(1);
                }
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};