/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
 */

class Solution {
    vector<bool> visited;

  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        int maxEle = INT_MIN;
        for (int ele : nums) {
            sum += ele;
            maxEle = max(maxEle, ele);
        }
        visited = vector<bool>(nums.size(), false);
        int targetSum = sum / k;
        if (sum % k != 0 || maxEle > targetSum) {
            return false;
        }
        return canPartitionUtil(nums, k, targetSum, 0, 0);
    }

    bool canPartitionUtil(vector<int> &nums, int k, int &targetSum, int index, int currentSum) {
        if (k == 1) {
            return true;
        }
        if (targetSum == currentSum) {
            return canPartitionUtil(nums, k - 1, targetSum, 0, 0);
        }
        for (int i = index; i < nums.size(); i++) {
            if (!visited[i] && currentSum + nums[i] <= targetSum) {
                visited[i] = true;
                if (canPartitionUtil(nums, k, targetSum, i + 1, currentSum + nums[i])) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};