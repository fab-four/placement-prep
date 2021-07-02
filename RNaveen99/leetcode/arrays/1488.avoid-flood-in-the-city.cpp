/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/avoid-flood-in-the-city/
 */

class Solution {
  public:
    vector<int> avoidFlood(vector<int> &rains) {
        int size = rains.size();
        vector<int> ans(size, 1);
        // lakeNumber -> DayNumber
        unordered_map<int, int> fullLakes;
        set<int> dryDays;
        for (int i = 0; i < size; i++) {
            if (rains[i] == 0) {
                dryDays.emplace(i);
            } else {
                if (fullLakes.count(rains[i])) {
                    auto itr = dryDays.lower_bound(fullLakes[rains[i]]);
                    if (itr == dryDays.end()) {
                        return {};
                    }
                    ans[*itr] = rains[i];
                    dryDays.erase(itr);
                }
                ans[i] = -1;
                fullLakes[rains[i]] = i;
            }
        }
        return ans;
    }
};