/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
 */

// Index  = 0 1  2 3  4
// A      = 1 2 -2 4 -4
// preSum = 1 3  1 5  1

vector<int> Solution::lszero(vector<int> &A) {

    unordered_map<int, int> m;
    int preSum = 0;

    int maxLen = 0, currLen = 0;
    int start = 0, end = 0;

    // for sequences which get presum 0
    m[0] = -1;

    for (int i = 0; i < A.size(); ++i) {
        preSum += A[i];
        // if preSum is found ... => preSum has fully canceled previous values => sum = 0
        if (m.find(preSum) == m.end()) {
            m[preSum] = i;
        } else {
            currLen = i - m[preSum];
            if (currLen > maxLen) {
                maxLen = currLen;
                start = m[preSum] + 1;
                end = i + 1;
            }
        }
    }
    vector<int> res;
    for (int i = start; i < end; ++i) {
        res.push_back(A[i]);
    }
    return res;
}
