// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
  // Time Complexity : O(n^2)
  // Space Complexity : O(n^2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; j++) {
                temp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(std::move(temp));
        }
        return res;
    }
};
