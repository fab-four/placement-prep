/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/merge-intervals/
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
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
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

vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    vector<Interval> result;
    int i;
    for (i = 0; i < A.size(); i++) {
        if (A[i].start <= newInterval.start) {
            result.emplace_back(A[i]);
        } else {
            break;
        }
    }
    if (i == 0) {
        result.emplace_back(newInterval);
    } else {
        if (newInterval.start <= result[result.size() - 1].end)
            result[result.size() - 1].end = max(result[result.size() - 1].end, newInterval.end);
        else
            result.push_back(newInterval);
    }

    for (; i < A.size(); i++) {
        if (A[i].start <= result[result.size() - 1].end)
            result[result.size() - 1].end = max(result[result.size() - 1].end, A[i].end);
        else
            result.push_back(A[i]);
    }
    return result;
}