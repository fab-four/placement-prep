/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/maximum-ones-after-modification/
 */

int Solution::solve(vector<int> &A, int B) {
    int size = A.size();
    int cnt0 = 0;
    int left = 0;
    int max_len = 0;

    // i decides current ending point
    for (int i = 0; i < size; i++) {
        if (a[i] == 0)
            cnt0++;

        // If there are more 0's move left point for current ending point.
        while (cnt0 > B) {
            if (a[left] == 0)
                cnt0--;
            left++;
        }

        max_len = max(max_len, i - left + 1);
    }

    return max_len;
}