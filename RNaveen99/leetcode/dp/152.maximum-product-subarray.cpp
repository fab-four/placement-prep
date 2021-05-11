/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-product-subarray/
 */

// 1. It's really about odd negative numbers or even negative numbers, if it's odd, either the left end one or
// the right end one should be counted, so it will be revealed by scanning from left and from right in 2
// passes.
// 2. 0 is a kind of delimiter, product accumulation will be reset to 1
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int maxProduct = INT_MIN;
        int product = 1;

        for (int i = 0; i < nums.size(); i++) {
            product = product * nums[i];
            maxProduct = max(maxProduct, product);
            if (product == 0) {
                product = 1;
            }
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product = product * nums[i];
            maxProduct = max(maxProduct, product);
            if (product == 0) {
                product = 1;
            }
        }
        return maxProduct;
    }
};