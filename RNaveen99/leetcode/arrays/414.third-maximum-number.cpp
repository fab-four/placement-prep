/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/third-maximum-number/
 */
 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int *first = nullptr;
        int *second = nullptr;
        int *third = nullptr; 
        for (int i = 0; i < nums.size(); i++) {
            if (first != nullptr && nums[i] == (*first) || second  != nullptr && nums[i] == (*second) || third != nullptr && nums[i] == (*third)) continue;
            if (first == nullptr || nums[i] > *first) {
                third = second;
                second = first;
                first = &nums[i];
            } else if (second == nullptr || nums[i] > *second) {
                third = second;
                second = &nums[i];
            } else if (third == nullptr || nums[i] > *third) {
                third = &nums[i];
            }
        }
        return third ? *third : *first;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> hash;
        for (int ele : nums) {
            hash.insert(ele);
            if (hash.size() > 3) {
                hash.erase(hash.begin());
            }
        }
        return hash.size() == 3 ? *hash.begin() : *hash.rbegin();
    }
};