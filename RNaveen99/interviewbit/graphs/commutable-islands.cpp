/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/commutable-islands/
 */

// MST
int find(vector<int> &parent, int i) {
    if (parent[i] < 0) {
        return i;
    }
    int temp = find(parent, parent[i]);
    parent[i] = temp;
    return temp;
}

int Solution::solve(int A, vector<vector<int>> &B) {
    sort(B.begin(), B.end(), [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });
    vector<int> parent(A, -1);
    int ans = 0;
    for (int i = 0; i < B.size(); i++) {
        int up = find(parent, B[i][0] - 1);
        int vp = find(parent, B[i][1] - 1);
        if (up != vp) {
            int rankU = -parent[up];
            int rankV = -parent[vp];
            if (rankU < rankV) {
                parent[up] = vp;
            } else if (rankU > rankV) {
                parent[vp] = up;
            } else {
                parent[up] = vp;
                rankV++;
                parent[vp] = -rankV;
            }
            ans += B[i][2];
        }
    }
    return ans;
}