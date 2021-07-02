/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/non-decreasing-array/
 */

// Modifying the original array
class Solution {
  public:
    bool checkPossibility(vector<int> &nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return count <= 1;
    }
};

//     A
//
// Y1             Y2
//
//           B
// Without modifying
// return false if we see (count > 1) or if we see the (Y1 A B Y2) scenario.
// i.e. (Y1 > B) && (A > Y2)
// https://leetcode.com/problems/non-decreasing-array/discuss/1190763/JS-Python-Java-C%2B%2B-or-Simple-Solution-w-Visual-Explanation
class Solution {
  public:
    bool checkPossibility(vector<int> &nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (count || (i > 1 && i < nums.size() - 1) &&
                                 ((nums[i - 2] > nums[i]) && (nums[i + 1] < nums[i - 1]))) {
                    return false;
                }
                count++;
            }
        }
        return true;
    }
};