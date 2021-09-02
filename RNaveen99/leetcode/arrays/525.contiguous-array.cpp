/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/contiguous-array/
 */

// Reference :
// https://leetcode.com/problems/contiguous-array/discuss/99655/Python-O(n)-Solution-with-Visual-Explanation

class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        int length = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (m.count(sum)) {
                length = max(length, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return length;
    }
};