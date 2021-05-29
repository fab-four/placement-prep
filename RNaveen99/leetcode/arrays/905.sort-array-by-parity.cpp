/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sort-array-by-parity/
 */

class Solution {
  public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int evenPointer = 0;
        for (int i = 0; i < A.size(); i++) {
            if (!(A[i] & 1)) {
                swap(A[evenPointer++], A[i]);
            }
        }
        return A;
    }
};