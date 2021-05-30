/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/maximum-sum-combinations/
 */

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> ans;

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> seen;

    int idx_A = A.size() - 1;
    int idx_B = B.size() - 1;
    int sum = A[idx_A] + B[idx_B];

    pq.push({sum, {idx_A, idx_B}});
    seen.insert({idx_A, idx_B});

    while (C--) {
        auto curr = pq.top();
        pq.pop();

        ans.push_back(curr.first);

        idx_A = curr.second.first;
        idx_B = curr.second.second;
        pair<int, int> nextIndexes;
        if (idx_A >= 1) {
            sum = A[idx_A - 1] + B[idx_B];
            nextIndexes = {idx_A - 1, idx_B};
            if (seen.count(nextIndexes) == 0) {
                pq.push({sum, nextIndexes});
                seen.insert(nextIndexes);
            }
        }

        if (idx_B >= 1) {
            sum = A[idx_A] + B[idx_B - 1];
            nextIndexes = {idx_A, idx_B - 1};
            if (seen.count(nextIndexes) == 0) {
                pq.push({sum, nextIndexes});
                seen.insert(nextIndexes);
            }
        }
    }
    return ans;
}