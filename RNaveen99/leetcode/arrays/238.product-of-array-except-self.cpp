/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/product-of-array-except-self/
 */

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> leftProduct(size);
        leftProduct[0] = nums[0];
        for (int i = 1; i < size; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i];
        }
        vector<int> rightProduct(size);
        rightProduct[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i + 1] * nums[i];
        }
        vector<int> result(size);
        result[0] = rightProduct[1];
        result[size - 1] = leftProduct[size - 2];

        for (int i = 1; i < size - 1; i++) {
            result[i] = leftProduct[i - 1] * rightProduct[i + 1];
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> result(size);
        result[0] = 1;
        for (int i = 1; i < size; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] = result[i] * right;
            right = right * nums[i];
        }

        return result;
    }
};