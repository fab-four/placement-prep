/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/merge-overlapping-intervals/
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool mycomp(Interval a, Interval b) { return a.start < b.start; }

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), mycomp);
    vector<Interval> res;
    int n = A.size();
    res.push_back(A[0]);
    for (int i = 1; i < n; i++) {
        if (A[i].start <= res[res.size() - 1].end)
            res[res.size() - 1].end = max(res[res.size() - 1].end, A[i].end);
        else
            res.push_back(A[i]);
    }
    return res;
}