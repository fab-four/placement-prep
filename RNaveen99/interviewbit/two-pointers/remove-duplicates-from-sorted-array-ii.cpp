/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
 */

int Solution::removeDuplicates(vector<int> &A) {
    int count = 0;
    int size = A.size();
    for (auto i = 0; i < size; ++i) {
        if (i < size - 2 && A[i] == A[i + 1] && A[i] == A[i + 2])
            continue;
        else
            A[count++] = A[i];
    }
    return count;
}