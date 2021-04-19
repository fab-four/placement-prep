/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/wave-array/
 */

vector<int> Solution::wave(vector<int> &A) {
    std::sort(A.begin(), A.end());
    int n = A.size();
    for (int i = 0; i < n - 1; i += 2)
        swap(A[i], A[i + 1]);
    return A;
}