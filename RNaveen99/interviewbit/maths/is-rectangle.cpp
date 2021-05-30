/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/is-rectangle/
 */

int Solution::solve(int A, int B, int C, int D) {
    vector<int> arr = {A, B, C, D};
    sort(arr.begin(), arr.end());
    return ((arr[0] == arr[1]) && (arr[2] == arr[3]));
}