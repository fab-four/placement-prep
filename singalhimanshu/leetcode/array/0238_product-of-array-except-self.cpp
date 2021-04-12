// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> output(nums.size());
    int prod = 1;
    for (int i = 0; i < nums.size(); i++) {
      output[i] = prod;
      prod *= nums[i];
    }
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      output[i] *= prod;
      prod *= nums[i];
    }
    return output;
  }
};
