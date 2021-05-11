/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution {
  public:
    int findLengthOfLCIS(vector<int> &nums) {
        int start = 0;
        int globalMax = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                if (i - start + 1 > globalMax) {
                    globalMax = i - start + 1;
                }
            } else {
                start = i;
            }
        }
        return globalMax;
    }
};