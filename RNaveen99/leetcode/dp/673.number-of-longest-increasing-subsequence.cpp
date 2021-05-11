/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 */

// LIS[k]      is the length of longest subsequence ending with nums[k];
// countLIS[k] is total number of longest subsequence ending with nums[k];

class Solution {
  public:
    int findNumberOfLIS(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;

        vector<int> LIS(nums.size(), 1);
        vector<int> countLIS(nums.size(), 1);
        int longestLIS = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (LIS[i] < LIS[j] + 1) {
                        LIS[i] = LIS[j] + 1;
                        countLIS[i] = countLIS[j];
                    } else if (LIS[i] == LIS[j] + 1) {
                        countLIS[i] += countLIS[j];
                    }
                }
            }
            longestLIS = max(longestLIS, LIS[i]);
        }

        int res = 0;
        for (int i = 0; i < LIS.size(); ++i) {
            if (LIS[i] == longestLIS) {
                res += countLIS[i];
            }
        }
        return res;
    }
};