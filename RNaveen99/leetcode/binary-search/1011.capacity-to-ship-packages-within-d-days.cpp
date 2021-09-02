/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 */

class Solution {
  public:
    int shipWithinDays(vector<int> &weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            int daysUsed = 1;
            int sum = 0;
            for (int i = 0; i < weights.size() && daysUsed <= days; i++) {
                if (sum + weights[i] <= mid) {
                    sum += weights[i];
                } else {
                    sum = weights[i];
                    daysUsed++;
                }
            }
            if (daysUsed > days)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};