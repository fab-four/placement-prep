/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/next-greater-element-i/
 */

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]] = i;
        }
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (hash.find(nums2[i]) != hash.end()) {
                if (s.empty()) {
                    nums1[hash[nums2[i]]] = -1;
                } else {
                    nums1[hash[nums2[i]]] = s.top();
                }
            }
            s.emplace(nums2[i]);
        }
        return nums1;
    }
};