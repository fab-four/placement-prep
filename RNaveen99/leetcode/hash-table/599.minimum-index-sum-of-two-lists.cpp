/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 */

class Solution {
  public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        if (list1.size() < list2.size())
            return findRestaurant(list2, list1);
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }
        int minIndexSum = INT_MAX;
        vector<string> result;

        for (int i = 0; i < list2.size(); i++) {
            if (m.find(list2[i]) != m.end()) {
                int indexSum = m[list2[i]] + i;

                if (indexSum < minIndexSum) {
                    minIndexSum = indexSum;
                    result.clear();
                    result.emplace_back(list2[i]);
                } else if (indexSum == minIndexSum) {
                    result.emplace_back(list2[i]);
                }
            }
        }
        return result;
    }
};