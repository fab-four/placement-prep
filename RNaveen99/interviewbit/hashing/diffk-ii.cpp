/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/diffk-ii/
 */

int Solution::diffPossible(const vector<int> &A, int k) {
    unordered_set<int> s;
    for (auto x : A) {
        if (s.count(x - k) || s.count(x + k))
            return true;
        s.insert(x);
    }
    return false;
}