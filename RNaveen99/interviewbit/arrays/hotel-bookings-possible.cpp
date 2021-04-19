/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/hotel-bookings-possible/
 */

// similar to finding the depth in interval partitioning problem
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    for (int i = 0, j = 0, c = 0; i < arrive.size() && j < depart.size();) {
        if (arrive[i] < depart[j])
            c++, i++;
        else
            c--, j++;
        if (c > K)
            return false;
    }

    return true;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    vector<pair<int, int>> v;
    int n = arrive.size();
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(arrive[i], 1));
        v.push_back(make_pair(depart[i], -1));
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < 2 * n; i++) {
        count += v[i].second;
        if (count > k)
            return false;
    }
    return true;
}