/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
 */

class Solution {
  public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
        return max(maxSumTwoNoOverlapUtil(A, L, M), maxSumTwoNoOverlapUtil(A, M, L));
    }
    int maxSumTwoNoOverlapUtil(vector<int> &A, int L, int M) {
        int sum = 0;
        int size = A.size();

        // it excludes element at i'th index
        vector<int> leftSum(size + 1, 0);

        // it includes element at i'th index
        vector<int> rightSum(size + 1, 0);

        int c_sumL = 0;
        int c_sumR = 0;
        for (int i = 0, j = size - 1; i < size; i++, j--) {
            c_sumL += A[i];
            c_sumR += A[j];

            leftSum[i + 1] = max(leftSum[i], c_sumL);
            rightSum[j] = max(rightSum[j + 1], c_sumR);

            if (i + 1 >= L) {
                c_sumL -= A[i + 1 - L];
            }
            if (i + 1 >= M) {
                c_sumR -= A[j + M - 1];
            }
        }

        for (int i = 0; i < size; i++) {
            sum = max(sum, leftSum[i] + rightSum[i]);
        }
        return sum;
    }
};