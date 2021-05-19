/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/array-3-pointers/
 */

int Solution::minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    int diff = INT_MAX, minimum = INT_MAX, maximum = INT_MIN;
    for (int i = 0, j = 0, k = 0; i < a.size() && j < b.size() && k < c.size();) {
        minimum = min(a[i], min(b[j], c[k]));
        maximum = max(a[i], max(b[j], c[k]));
        diff = min(diff, maximum - minimum);
        if (diff == 0)
            break;
        if (a[i] == minimum)
            i++;
        else if (b[j] == minimum)
            j++;
        else
            k++;
    }
    return diff;
}