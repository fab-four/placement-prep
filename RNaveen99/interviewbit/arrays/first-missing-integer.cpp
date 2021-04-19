/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/first-missing-integer/
 */

// place every positive integer on its correct
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1)
            return (i + 1);
    }
    return n + 1;
}

int Solution::firstMissingPositive(vector<int> &A) {
    // segregate +ve
    int j = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > 0) {
            swap(A[j], A[i]);
            j++;
        }
    }

    // first j elements are now +ve
    for (int i = 0; i < j; ++i) {
        int index = abs(A[i]) - 1;
        if (index < j && A[index] > 0) {
            A[index] *= -1;
        }
    }

    for (int i = 0; i < j; ++i) {
        // if A[i] > 0, means there was no index present which could negate A[i]
        if (A[i] > 0) {
            return i + 1; // +1 done to handle index
        }
    }

    return j + 1;
}