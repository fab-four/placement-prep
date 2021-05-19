/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/max-continuous-series-of-1s/
 */

vector<int> Solution::maxone(vector<int> &arr, int m) {
    int n = arr.size();
    int i = 0, j = 0;
    int ofs = 0, w = 0;
    int zeros = 0;

    while (j < n) {
        if (zeros <= m) {
            if (arr[j] == 0)
                zeros++;
            j++;
        }
        if (zeros > m) {
            if (arr[i] == 0)
                zeros--;
            i++;
        }
        if (j - i > w) {
            w = j - i;
            ofs = i;
        }
    }

    vector<int> best(w);
    iota(best.begin(), best.end(), ofs);
    return best;
}