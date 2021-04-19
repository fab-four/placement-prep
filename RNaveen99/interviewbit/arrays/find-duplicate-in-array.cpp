/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/find-duplicate-in-array/
 */

// n+1 elements given, range is 1 to n, one element is repeated
// simply xor all array elements and elements 1 to n.
//  1 to n will form xor pairs and cancel out. Duplicated one wil be left.
//  This method can only be used when a single duplicate is there [3, 4, 1, 4, 2].fails when
//  multiple duplicates like [ 3, 4, 1, 4, 1].
int Solution::repeatedNumber(const vector<int> &A) {
    int x = 0;
    int y = A[0];
    for (int i = 1; i < A.size(); i++) {
        x ^= i;
        y ^= A[i];
    }
    return x ^ y;
}

int repeatedNumber(vector<int> &A) {

    for (int i = 0; i < A.size(); ++i) {

        if (A[abs(A[i]) - 1] > 0) {
            A[abs(A[i]) - 1] *= -1;
        } else {
            // element is already negative, means its index has been repeated.
            return (abs(A[i]) - 1) + 1;
        }
    }
    return -1;
}

int findDuplicate(int[] nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}