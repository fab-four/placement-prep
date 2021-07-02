/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sliding-window-median/
 */

// sliding window
class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        vector<double> medians;
        auto mid = next(window.begin(), k / 2);
        medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
        for (int i = k; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            // Erase nums[i-k].
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i - k]));
            medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
        }
        return medians;
    }
};