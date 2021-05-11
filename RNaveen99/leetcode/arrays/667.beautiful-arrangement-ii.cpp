/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/beautiful-arrangement-ii/
 */

// To achieve k unique differences simply do this:
//      1. choose one from top
//      2. choose one from bottom
// and then repeat steps (1,2) k times.
// And then fill in the rest of the array in asc or desc order (depending on if we choose from top or bottom
// on the last iteration).

class Solution {
  public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);

        int start = 1;
        int last = n;
        int i = 0;
        for (int choice = 1; i < k; i++) {
            if (choice) {
                result[i] = start++;
            } else {
                result[i] = last--;
            }
            choice ^= 1;
        }

        if (i & 1) {
            while (start <= last) {
                result[i++] = start++;
            }
        } else {
            while (start <= last) {
                result[i++] = last--;
            }
        }
        return result;
    }
};