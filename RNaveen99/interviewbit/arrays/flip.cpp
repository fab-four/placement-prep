/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/flip/
 */

// choose that substring that has max no. of zeroes & minimum no. of zeroes
// i.e. choose substring that maximizes (#0's - #1's)

// kadane's algorithm
vector<int> Solution::flip(string A) {
    int globalMax = INT_MIN;
    int currentMax = INT_MIN;
    int currentStart = -1;
    int globalStart = -1;
    int end = -1;

    int num = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '0')
            num = 1;
        else
            num = -1;
        if (currentMax >= 0) {
            currentMax += num;
        } else {
            currentStart = i;
            currentMax = num;
        }
        if (currentMax > globalMax) {
            globalMax = currentMax;
            globalStart = currentStart;
            end = i;
        }
    }
    if (globalMax > 0) {
        return {globalStart + 1, end + 1};
    } else {
        return {};
    }
}
