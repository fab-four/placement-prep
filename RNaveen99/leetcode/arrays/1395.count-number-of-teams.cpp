/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/count-number-of-teams/
 */

class Solution {
  public:
    int numTeams(vector<int> &rating) {
        int size = rating.size();
        int result = 0;

        for (int i = 1; i + 1 < size; i++) {
            int leftIncrease = 0, leftDecrease = 0;
            int rightIncrease = 0, rightDecrease = 0;

            for (int j = 0; j < size; j++) {
                if (i == j || rating[i] == rating[j])
                    continue;
                if (j < i) {
                    if (rating[j] < rating[i]) {
                        leftIncrease++;
                    } else {
                        leftDecrease++;
                    }
                } else {
                    if (rating[i] < rating[j]) {
                        rightIncrease++;
                    } else {
                        rightDecrease++;
                    }
                }
            }
            result += leftIncrease * rightIncrease + leftDecrease * rightDecrease;
        }
        return result;
    }
};