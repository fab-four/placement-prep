/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/range-sum-query-immutable/
 */

class NumArray {
    vector<int> sums;

  public:
    NumArray(vector<int> &nums) {
        sums.push_back(nums[0]);
        for (int i = 0; i < nums.size(); ++i) {
            sums.push_back(nums[i] + sums[i]);
        }
    }

    int sumRange(int left, int right) { return sums[right + 1] - sums[left]; }
};