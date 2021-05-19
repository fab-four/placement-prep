/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/distribute-candy/
 */

int Solution::candy(vector<int> &ratings) {
    int candies = 0;
    int size = ratings.size();
    vector<int> left(size, 1);
    vector<int> right(size, 1);

    for (auto l = 1; l < size; ++l)
        if (ratings[l] > ratings[l - 1])
            left[l] = left[l - 1] + 1;

    for (auto r = size - 2; r >= 0; --r)
        if (ratings[r] > ratings[r + 1])
            right[r] = right[r + 1] + 1;

    for (auto i = 0; i < size; ++i)
        candies += max(left[i], right[i]);

    return candies;
}

int Solution::candy(vector<int> &children) {
    int n = children.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++) {
        if (children[i] > children[i - 1]) {
            ans[i] = ans[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (children[i] > children[i + 1]) {
            ans[i] = max(ans[i], ans[i + 1] + 1);
        }
    }
    return accumulate(ans.begin(), ans.end(), 0);
}