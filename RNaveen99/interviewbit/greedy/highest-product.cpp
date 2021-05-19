/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/highest-product/
 */

int Solution::maxp3(vector<int> &A) {
    auto n = A.size();
    sort(A.begin(), A.end());
    int allPositives = A[n - 1] * A[n - 2] * A[n - 3];
    int twoNegatives = A[n - 1] * A[0] * A[1];
    return max(allPositives, twoNegatives);
}