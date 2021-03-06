/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/contains-duplicate-ii/
 */

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                if (abs(m[nums[i]] - i) <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

// uses sliding window
class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};