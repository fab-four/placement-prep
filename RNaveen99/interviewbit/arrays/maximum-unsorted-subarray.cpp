/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/maximum-unsorted-subarray/
 */

// Assume that A[l], ..., A[r] is the minimum-unsorted-subarray which is to be sorted, then
// subarrays A[0], ... , A[l-1] and A[r+1], ... , A[N-1] will be in sorted(ascending) order.

// => min(A[l],...,A[r]) >= max(A[0], ..., A[l-1]) and max(A[l],...,A[r]) <= min(A[r+1],...,A[N-1])

vector<int> Solution::subUnsort(vector<int> &arr) {

    int size = arr.size();
    int left = 0, right = size - 1;

    int i, maximum = INT_MIN, minimum = INT_MAX;

    // starting of unsorted subarray
    for (left = 0; left < size - 1; left++) {
        if (arr[left] > arr[left + 1])
            break;
    }
    if (left == size - 1) {
        // The complete array is sorted
        return {-1};
    }

    // ending of unsorted subarray
    for (right = size - 1; right > 0; right--) {
        if (arr[right] < arr[right - 1])
            break;
    }

    // find minimum and maximum element of unsorted subarray
    for (i = left; i <= right; i++) {
        maximum = max(maximum, arr[i]);
        minimum = min(minimum, arr[i]);
    }

    // compare minimum with left half
    for (i = 0; i < left; i++) {
        if (arr[i] > minimum) {
            left = i;
            break;
        }
    }

    // compare maximum with right half
    for (i = size - 1; i > right; i--) {
        if (arr[i] < maximum) {
            right = i;
            break;
        }
    }

    return {left, right};
}