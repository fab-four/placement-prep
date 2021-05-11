/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/valid-triangle-number/
 */

class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        int count = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); i++) {
            for (int j = i + 1, k = i + 2; j + 1 < nums.size() && nums[i] != 0; j++) {
                while (k < nums.size() && (nums[i] + nums[j] > nums[k])) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};

class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        int count = 0;
        sort(nums.begin(), nums.end());

        for (int k = nums.size() - 1; k > 1; k--) {
            for (int i = 0, j = k - 1; i < j;) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};