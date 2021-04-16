/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/subsets-ii/
 */

class Solution {
    vector<vector<int>> allSubsets;

  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        subsetsUtil(nums, 0, subset);
        return allSubsets;
    }
    void subsetsUtil(vector<int> &nums, int start, vector<int> &subset) {
        allSubsets.emplace_back(subset);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            subset.emplace_back(nums[i]);
            subsetsUtil(nums, i + 1, subset);
            subset.pop_back();
        }
    }
};