/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/distinct-numbers-in-window/
 */

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ret;
    if (B > n) {
        return ret;
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[A[i]]++;
        if (i + 1 >= B) {
            ret.push_back(m.size());
            m[A[i + 1 - B]]--;
            if (m[A[i + 1 - B]] == 0)
                m.erase(A[i + 1 - B]);
        }
    }
    return ret;
}