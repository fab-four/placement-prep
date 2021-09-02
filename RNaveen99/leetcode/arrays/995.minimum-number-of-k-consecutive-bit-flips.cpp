/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
 */

// Reference :
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/239284/C++-greedy-stack-and-O(1)-memory/649268

// We can use our queue to keep track of how many times the window/interval has been flipped and whats the
// last index (end of any k -window) of a current interval that was flipped and keep popping off these indexes
// from the queue when we are done with traversing that k-interval.

class Solution {
  public:
    int minKBitFlips(vector<int> &nums, int k) {
        int size = nums.size();
        queue<int> flips;
        int count = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                if (flips.empty() || flips.size() % 2 == 0) {
                    count++;
                    flips.emplace(i + k - 1);
                }
            } else {
                if (flips.size() % 2 == 1) {
                    count++;
                    flips.emplace(i + k - 1);
                }
            }
            if (!flips.empty() && flips.front() <= i) {
                flips.pop();
            }
        }
        if (flips.empty()) {
            return count;
        }
        return -1;
    }
};