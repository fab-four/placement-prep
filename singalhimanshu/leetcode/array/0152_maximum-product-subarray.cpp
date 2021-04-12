// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/maximum-product-subarray/

constexpr int mmin = numeric_limits<int>::min();

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int best = mmin;
    int pos_product = 1;
    int neg_product = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) {
        swap(pos_product, neg_product);
      }
      pos_product = max(pos_product * nums[i], nums[i]);
      neg_product = min(neg_product * nums[i], nums[i]);
      best = max(best, pos_product);
    }
    return best;
  }
};
