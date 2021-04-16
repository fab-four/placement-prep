/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/subsets/
 */

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> subsets;
        for (int i = 0; i < 1 << nums.size(); i++) {
            vector<int> subset;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    subset.emplace_back(nums[j]);
                }
            }
            subsets.emplace_back(subset);
        }
        return subsets;
    }
};

class Solution {
    vector<vector<int>> allSubsets;

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> subset;
        subsetsUtil(nums, 0, subset);
        return allSubsets;
    }
    void subsetsUtil(vector<int> &nums, int start, vector<int> &subset) {
        allSubsets.emplace_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.emplace_back(nums[i]);
            subsetsUtil(nums, i + 1, subset);
            subset.pop_back();
        }
    }
};