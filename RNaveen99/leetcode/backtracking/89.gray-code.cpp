/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/gray-code/
 */

class Solution {
  public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i = 0; i < n; i++) {
            int size = res.size();
            for (int j = size - 1; j >= 0; j--) {
                res.push_back(res[j] | 1 << i);
            }
        }
        return res;
    }
};