/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/max-non-negative-subarray/
 */

vector<int> Solution::maxset(vector<int> &A) {
    long globalMax = 0, globalStart = 0, globalEnd = -1;
    long currentMax = 0, currentStart = -1;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= 0) {
            if (currentStart == -1) {
                currentStart = i;
            }
            currentMax += A[i];

            if (currentMax > globalMax) {
                globalMax = currentMax;
                globalStart = currentStart;
                globalEnd = i;
            } else if (currentMax == globalMax) {
                if (i - currentStart + 1 > globalEnd - globalStart + 1) {
                    globalStart = currentStart;
                    globalEnd = i;
                }
            }
        } else {
            currentMax = 0;
            currentStart = -1;
        }
    }
    return {A.cbegin() + globalStart, A.cbegin() + globalEnd + 1};
}
