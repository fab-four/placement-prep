/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/first-missing-positive/
 */

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }
};

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0 || nums[i] > size) {
                nums[i] = size + 1;
            }
        }
        for (int i = 0; i < size; i++) {
            int num = abs(nums[i]);
            if (num == size + 1) {
                continue;
            }
            int index = num - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }
};