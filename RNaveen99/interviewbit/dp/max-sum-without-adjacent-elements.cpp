/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
 */

// similar to house robber
int Solution::adjacent(vector<vector<int>> &arr) {
    int n = arr[0].size();
    int A = 0, B = max(arr[0][0], arr[1][0]);
    for (int j = 1; j < n; j++) {
        int temp = max(A, B);
        B = A + max(arr[0][j], arr[1][j]);
        A = temp;
    }
    return max(A, B);
}

int Solution::adjacent(vector<vector<int>> &arr) {
    int n = arr[0].size();
    int A = 0, B = max(arr[0][0], arr[1][0]);
    for (int j = 1; j < n; j++) {
        int temp = max(A + max(arr[0][j], arr[1][j]), B);
        A = B;
        B = temp;
    }
    return B;
}