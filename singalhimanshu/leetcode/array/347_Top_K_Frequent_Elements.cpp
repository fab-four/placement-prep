class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }
    vector<vector<int>> buckets(nums.size() + 1);
    for (const auto &[key, value] : freq) {
      buckets[value].push_back(key);
    }
    reverse(begin(buckets), end(buckets));
    vector<int> res;
    res.reserve(k);
    for (const auto &bucket : buckets) {
      for (int ele : bucket) {
        res.push_back(ele);
        if (res.size() == k) {
          return res;
        }
      }
    }
    return res;
  }
};
