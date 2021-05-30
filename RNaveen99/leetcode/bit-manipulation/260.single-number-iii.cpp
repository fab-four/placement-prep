/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/single-number-iii/
 */

// https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C++Java-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations/263807

class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        long aXORb = 0;
        for (int ele : nums) {
            aXORb = aXORb ^ ele;
        }
        long diff = aXORb & (~(aXORb - 1));
        // int diff = aXORb & (-aXORb);

        int a = 0;
        int b = 0;

        for (int ele : nums) {
            if (diff & ele) {
                a = a ^ ele;
            } else {
                b = b ^ ele;
            }
        }
        return {a, b};
    }
};