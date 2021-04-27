/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/subarray-sum-equals-k/
 */

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int count = 0;
        int c_sum = 0;
        unordered_map<int, int> sumFrequency;
        // sumFrequency[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            c_sum += nums[i];
            int residual = c_sum - k;
            if (residual == 0)
                count++;

            if (sumFrequency.find(residual) != sumFrequency.end()) {
                count += sumFrequency[residual];
            }
            sumFrequency[c_sum]++;
        }
        return count;
    }
};