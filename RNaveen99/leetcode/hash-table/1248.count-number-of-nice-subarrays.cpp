/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/count-number-of-nice-subarrays/
 */

// Reference :
// https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/508217/C%2B%2B%3A-Visual-explanation.-O(1)-space.-Two-pointers

class Solution {
  public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int odds = 0;
        int count = 0;
        int result = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] & 1) {
                odds++;
                count = 0;
            }

            while (odds == k) {
                if (nums[left] & 1)
                    odds--;
                count++;
                left++;
            }
            result += count;
            right++;
        }
        return result;
    }
};

// same as subarray-sum-equals-k
// take odd number as 1 and even as 0
class Solution {
  public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int result = 0;
        int i = 0;
        int c_sum = 0;
        unordered_map<int, int> frequencySum;
        frequencySum[0] = 1;
        while (i < nums.size()) {
            if (nums[i] & 1) {
                c_sum++;
            }

            if (frequencySum.count(c_sum - k)) {
                result += frequencySum[c_sum - k];
            }
            frequencySum[c_sum]++;
            i++;
        }
        return result;
    }
};