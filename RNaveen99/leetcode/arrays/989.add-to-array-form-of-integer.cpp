/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/add-to-array-form-of-integer/
 */

class Solution {
  public:
    vector<int> addToArrayForm(vector<int> &nums, int k) {
        vector<int> result;
        int index = nums.size() - 1;
        int carry = 0;
        while (k || index >= 0 || carry) {
            int remainder = k % 10;
            if (k) {
                k = k / 10;
            }
            int sum = remainder + carry;
            if (index >= 0) {
                sum += nums[index--];
            }
            result.emplace_back(sum % 10);
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};