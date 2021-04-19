/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/maximum-absolute-difference/
 */

// Try to separate the terms of i and j.
// Separate them using negative sign because then the first one will act as max and second will act
// a min. Hence will give the max abs diff.Four cases:

// 1. A[i] > A[j] , i > j
//     => f(i, j) = (A[i] - A[j]) + (i-j) = (A[i]+i) - (A[j]+j)
// 2. A[i] < A[j] , i < j
//     => f(i, j) = -(A[i] - A[j]) + -(i-j) = -(A[i]+i) + (A[j]+j) = - ( (A[i]+i) - (A[j]+j) )
// 3. A[i] > A[j] , i < j
//      => f(i, j) = (A[i] - A[j]) + -(i-j) = (A[i]-i) - (A[j]-j)
// 4. A[i] < A[j] , i > j
//      => f(i, j) = -(A[i] - A[j]) + (i-j) = -(A[i]-i) + (A[j]-j) = - ( (A[i]-i) - (A[j]-j))

// We can see that 1 and 2 will give the same ans, 3 and 4 will also give the same ans.
// So we will find max and min for them. The maximum diff bn them will give the ans.

int Solution::maxArr(vector<int> &A) {

    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;

    int size = A.size();
    for (int i = 0; i < size; i++) {

        // for eq 1 & 2
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);

        // for eq 3 & 4
        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }
    int diff1 = max1 - min1;
    int diff2 = max2 - min2;

    // Calculating maximum absolute difference.
    return max(diff1, diff2);
}