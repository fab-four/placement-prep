/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/pair-with-given-difference/
 */

int Solution::solve(vector<int> &A, int target) {
    // x - y = target
    // x = target + y or y = x - target
    unordered_set<int> seen;
    for (const auto &ele : A) {
        if (seen.count(target + ele) > 0 || seen.count(ele - target)) {
            return 1;
        }
        seen.insert(ele);
    }
    return 0;
}