/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
 */

// 2 points(A, B) and (C, D).
// Note that what only matters is :
// X = abs(A - C) and Y = abs(B - D).
//
// While X and Y are positive, you will move along the diagonal and X and Y would both reduce by 1.
// When one of them becomes 0, you would move so that in each step the remaining number reduces
// by 1.
// In other words, the total number of steps would correspond to max(X, Y)

int Solution::coverPoints(vector<int> x, vector<int> y) {
    if (x.size() <= 1)
        return 0;
    assert(x.size() == y.size());
    int ans = 0;
    for (int i = 1; i < x.size(); i++) {
        ans += max(abs(x[i] - x[i - 1]), abs(y[i] - y[i - 1]));
    }
    return ans;
}