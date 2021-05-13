/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/min-sum-path-in-triangle/
 */

int Solution::minimumTotal(vector<vector<int>> &triangle) {
    int rows = triangle.size();

    vector<int> minlen(triangle.back());

    for (int layer = rows - 2; layer >= 0; layer--) {
        for (int i = 0; i <= layer; i++) {
            minlen[i] = triangle[layer][i] + min(minlen[i], minlen[i + 1]);
        }
    }
    return minlen[0];
}