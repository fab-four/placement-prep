/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
 */

vector<int> Solution::getRow(int k) {
    vector<int> res(k + 1, 1);
    int currLeft, nextLeft;
    for (int i = 2; i <= k; ++i) {
        currLeft = 1;
        for (int j = 1; j < i; ++j) {
            nextLeft = res[j];
            res[j] = currLeft + res[j];
            currLeft = nextLeft;
        }
    }
    return res;
}

vector<int> Solution::getRow(int k) {
    vector<int> r(k + 1);
    r[0] = 1;
    int val = 1;
    for (int i = 1; i <= k; i++) {
        val = (val * (k - i + 1) / i);
        r[i] = val;
    }
    return r;
}