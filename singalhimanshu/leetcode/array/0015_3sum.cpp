// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/3sum/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    auto n = nums.size();
    sort(begin(nums), end(nums));
    for (int i = 0; i < n; i++) {
      int target = -nums[i];
      int low = i + 1, high = n - 1;
      while (low < high) {
        if (nums[low] + nums[high] == target) {
          result.push_back({-target, nums[low], nums[high]});
          while (low < high && nums[low] == nums[low + 1]) {
            low++;
          }
          while (low < high && nums[high] == nums[high - 1]) {
            high--;
          }
          low++;
          high--;
        } else if (nums[low] + nums[high] < target) {
          low++;
        } else {
          high--;
        }
      }
      while (i + 1 < n && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return result;
  }
};
