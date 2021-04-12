// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/array-partition-i/

class Solution {
public:
  int arrayPairSum(vector<int> &nums) {
    sort(begin(nums), end(nums));
    int result = 0;
    for (int i = 0; i < nums.size() - 1; i += 2) {
      result += min(nums[i], nums[i + 1]);
    }
    return result;
  }
};
