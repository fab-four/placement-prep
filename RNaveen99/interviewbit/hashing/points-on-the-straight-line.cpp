/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/points-on-the-straight-line/
 */

// The slope can be a double value and can cause precision problems.
int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    map<pair<int, int>, int> M;
    int ans = 0;
    for (int i = 0; i < X.size(); i++) {
        M.clear();
        int samePoints = 1, curMax = 0;
        for (int j = i + 1; j < X.size(); j++) {
            int xdiff = X[i] - X[j];
            int ydiff = Y[i] - Y[j];
            if (xdiff == 0 && ydiff == 0) {
                // same points
                samePoints++;
                continue;
            }
            int g = __gcd(xdiff, ydiff);
            M[make_pair(xdiff / g, ydiff / g)]++;
            curMax = max(curMax, M[make_pair(xdiff / g, ydiff / g)]);
        }
        curMax += samePoints;
        ans = max(ans, curMax);
    }
    return ans;
}

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    unordered_map<string, int> M;
    int ans = 0;
    for (int i = 0; i < X.size(); i++) {
        M.clear();
        int samePoints = 1, curMax = 0;

        for (int j = i + 1; j < X.size(); j++) {
            int xdiff = X[i] - X[j];
            int ydiff = Y[i] - Y[j];
            if (xdiff == 0 && ydiff == 0) {
                // same points
                samePoints++;
                continue;
            }
            int g = __gcd(xdiff, ydiff);
            M[to_string(xdiff / g) + " " + to_string(ydiff / g)]++;
            curMax = max(curMax, M[to_string(xdiff / g) + " " + to_string(ydiff / g)]);
        }
        curMax += samePoints;
        ans = max(ans, curMax);
    }
    return ans;
}
