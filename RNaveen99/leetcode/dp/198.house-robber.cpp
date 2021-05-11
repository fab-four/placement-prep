/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/house-robber/
 */

// A robber has 2 options:
//      a) rob current house i;
//      b) don't rob current house.

// If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one
// before previous, i-2 and gets all cumulative loot that follows.

// If an option "b" is selected the robber gets all the possible loot from robbery of i - 1 and all the
// following buildings.

// So it boils down to calculating what is more profitable :
//      robbery of current house + loot from houses before the previous
//      loot from the previous house robbery and any loot captured before that

// rob(i) = max(rob(i - 2) + currentHouseValue, rob(i - 1))

class Solution {
  public:
    int rob(vector<int> &nums) {
        vector<int> profits(nums.size() + 1, 0);
        profits[0] = 0;
        profits[1] = nums[0];
        for (int i = 2; i < profits.size(); i++) {
            profits[i] = max(profits[i - 1], nums[i - 1] + profits[i - 2]);
        }
        return profits[nums.size()];
    }
};

class Solution {
  public:
    int rob(vector<int> &nums) {
        int first = 0;
        int second = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            int third = max(second, nums[i - 1] + first);
            first = second;
            second = third;
        }
        return second;
    }
};