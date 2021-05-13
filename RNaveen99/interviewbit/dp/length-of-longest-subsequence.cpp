/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/length-of-longest-subsequence/
 */

// Try to come up with something which stores length of increasing sequence upto a particular index and
// length of decreasing sequence from that particular index.
// Construct array inc[i] where inc[i] stores Longest Increasing subsequence ending with A[i].
// Construct array dec[i] where dec[i] stores Longest Decreasing subsequence starting with A[i].

// find the maximum value of(inc[i] + dec[i] - 1)

int Solution::longestSubsequenceLength(const vector &A) {
    int n = A.size();
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    int ct = 0;

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (A[i] > A[j])
                inc[i] = max(inc[i], inc[j] + 1);
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j])
                dec[i] = max(dec[i], dec[j] + 1);
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, inc[i] + dec[i] - 1);

    return mx;
}