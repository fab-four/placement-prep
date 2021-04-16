/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/zigzag-conversion/
 */

class Solution {
  public:
    string convert(string s, int numRows) {
        vector<string> tempRows(numRows);
        int row = 0;
        int i = 0;
        while (i < s.size()) {
            // columns
            for (row = 0; row < numRows && i < s.size(); row++, i++) {
                tempRows[row] += s[i];
            }
            // diagonal
            for (row = numRows - 2; row > 0 && i < s.size(); row--, i++) {
                tempRows[row] += s[i];
            }
        }
        string ss = "";
        for (row = 0; row < numRows; row++) {
            ss += tempRows[row];
        }
        return ss;
    }
};