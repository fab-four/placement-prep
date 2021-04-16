/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/permutations/
 */

class Solution {
  private:
    vector<vector<int>> permutations;

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        allPermutations(nums, 0, nums.size());
        return permutations;
    }

    void allPermutations(vector<int> &nums, int left, int right) {
        if (left == right) {
            permutations.push_back(nums);
            return;
        }

        for (int i = left; i < right; i++) {
            swap(nums[i], nums[left]);
            allPermutations(nums, left + 1, right);
            swap(nums[i], nums[left]);
        }
    }
};