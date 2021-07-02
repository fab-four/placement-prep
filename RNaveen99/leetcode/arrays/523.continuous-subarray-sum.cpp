/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/continuous-subarray-sum/
 */

class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int c_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            c_sum += nums[i];
            c_sum %= k;
            auto itr = m.find(c_sum);
            if (itr != m.end()) {
                if (i - itr->second > 1) {
                    return true;
                }
            } else {
                m[c_sum] = i;
            }
        }
        return false;
    }
};