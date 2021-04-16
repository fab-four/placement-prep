/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/single-number-ii/
 */

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        vector<int> counter(32, 0);
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < nums.size(); j++) {
                counter[i] += (nums[j] >> i) & 1;
            }

            int temp = (counter[i] % 3) << i;
            result = result | temp;
        }
        return result;
    }
};