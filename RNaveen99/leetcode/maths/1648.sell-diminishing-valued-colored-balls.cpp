/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
 */

class Solution {
  public:
    int maxProfit(vector<int> &inventory, int orders) {
        long res = 0, cols = 1;
        sort(inventory.begin(), inventory.end());

        for (int i = inventory.size() - 1; i >= 0 && orders > 0; --i, ++cols) {
            long currentHeight = inventory[i];
            int prevHeight = i > 0 ? inventory[i - 1] : 0;

            // complete rows to pick
            long completeRows = min(orders / cols, currentHeight - prevHeight);
            orders -= completeRows * cols;

            // n*(n+1)/2
            long temp = (currentHeight * (currentHeight + 1) -
                         (currentHeight - completeRows) * (currentHeight - completeRows + 1));
            res = (res + temp / 2 * cols) % 1000000007;

            if (currentHeight - prevHeight > completeRows) {
                res = (res + orders * (currentHeight - completeRows)) % 1000000007;
                break;
            }
        }
        return res;
    }
};