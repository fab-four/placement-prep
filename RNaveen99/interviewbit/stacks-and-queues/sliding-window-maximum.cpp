/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/sliding-window-maximum/
 */

vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    int n = arr.size();
    if (k >= n) {
        return vector<int>{*max_element(arr.begin(), arr.end())};
    }
    vector<int> ans;
    deque<int> Qi(k);
    int i;
    for (i = 0; i < k; i++) {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    for (; i < n; ++i) {
        ans.push_back([Qi.front()]);
        while ((!Qi.empty()) && Qi.front() <= i - k) {
            Qi.pop_front();
        }
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }

    ans.push_back([Qi.front()]);

    return ans;
}

vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    int n = arr.size();
    if (k >= n) {
        return vector<int>{*max_element(arr.begin(), arr.end())};
    }
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front() < i - k + 1) {
            q.pop_front();
        }
        while (!q.empty() && arr[q.back()] < arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) {
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}