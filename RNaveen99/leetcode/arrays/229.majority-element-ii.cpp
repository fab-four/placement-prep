/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/majority-element-ii/
 */

// Boyer-Moore Majority Vote algorithm
class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int A = 0;
        int B = 1;
        int countA = 0;
        int countB = 0;

        for (int ele : nums) {
            if (ele == A) {
                countA++;
            } else if (ele == B) {
                countB++;
            } else if (countA == 0) {
                A = ele;
                countA++;
            } else if (countB == 0) {
                B = ele;
                countB++;
            } else {
                countA--;
                countB--;
            }
        }
        countA = 0;
        countB = 0;

        for (int ele : nums) {
            if (ele == A)
                countA++;
            else if (ele == B)
                countB++;
        }
        int size = nums.size();
        int limit = floor(size / 3);
        vector<int> result;
        if (countA > limit)
            result.emplace_back(A);
        if (countB > limit)
            result.emplace_back(B);
        return result;
    }
};