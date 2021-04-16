/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-increasing-subsequence/
 */

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size());

        int globalMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currentMax = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    currentMax = max(currentMax, dp[j]);
                }
            }
            dp[i] = currentMax + 1;
            globalMax = max(globalMax, dp[i]);
        }
        return globalMax;
    }
};

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return res.size();
    }
};