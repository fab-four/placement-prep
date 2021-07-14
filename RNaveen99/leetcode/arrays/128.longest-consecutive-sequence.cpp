/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-consecutive-sequence/
 */

// T : O(nlog(n))
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums.size();
        sort(nums.begin(), nums.end());
        int current = 1;
        int longest = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    current++;
                } else {
                    current = 1;
                }
                longest = max(longest, current);
            }
        }
        return longest;
    }
};

// T : O(n)
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (!hash.count(num - 1)) {
                int temp = num;
                int currentLongest = 1;
                while (hash.count(temp + 1)) {
                    temp++;
                    currentLongest++;
                }
                longest = max(longest, currentLongest);
            }
        }
        return longest;
    }
};