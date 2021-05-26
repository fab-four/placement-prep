/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/pascals-triangle-ii/
 */

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev, curr;
        for (int i = 0; i <= rowIndex; i++) {
            curr.clear();
            for (int j = 0; j <= i; j++) {
                if (j > 0 && j < i) {
                    curr.push_back(prev[j - 1] + prev[j]);
                } else {
                    curr.push_back(1);
                }
            }
            prev = curr;
        }
        return curr;
    }
};