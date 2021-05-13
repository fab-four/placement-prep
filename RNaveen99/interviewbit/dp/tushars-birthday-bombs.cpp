/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/tushars-birthday-bombs/
 */

// R : Tushar's Resistance
// S : Strength
// Let the index of friend with minimum strength be F.(Take smallest index in case of a tie)
// It is obvious that -> Maximum no. of kicks = R / (S[F]).

// This is the length of the answer but since we need lexicographically smaller order (according to index),
// friends whose index is less than the F can also hit provided they do not change the length of the answer.

// There is also a crucial observation here, we need not consider the friend which have a friend to their left
// (lesser index) and have lesser than or equal strength than him. (Otherwise we can just take that friend
// with lesser index instead).

// Iterate through the candidate friend's vector formed and see if the friend at consideration can be
// used instead of the friend with minimum strength.

vector<int> Solution::solve(int W, vector<int> &wt) {
    vector<pair<int, int>> candidateFriends;
    int prev = INT_MAX;
    for (int i = 0; i < wt.size(); i++) {
        if (wt[i] < prev) {
            candidateFriends.push_back({i, wt[i]});
            prev = wt[i];
        }
    }
    int n = candidateFriends.size();
    vector<int> ans;
    int i = 0;
    int minimumStrength = candidateFriends[n - 1].second;
    while (i < n) {
        if (W >= candidateFriends[i].second &&
            (1 + (W - candidateFriends[i].second) / minimumStrength == (W / minimumStrength))) {
            ans.push_back(candidateFriends[i].first);
            W -= candidateFriends[i].second;
        } else {
            i++;
        }
    }
    return ans;
}