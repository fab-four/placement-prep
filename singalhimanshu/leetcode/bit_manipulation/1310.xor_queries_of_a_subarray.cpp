// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    vector<int> xor_prefix(arr.size());
    xor_prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      xor_prefix[i] = xor_prefix[i - 1] ^ arr[i];
    }
    vector<int> res;
    res.reserve(queries.size());
    for (const auto &query : queries) {
      if (query[0] == 0) {
        res.emplace_back(xor_prefix[query[1]]);
        continue;
      }
      res.emplace_back(xor_prefix[query[1]] ^ xor_prefix[query[0] - 1]);
    }
    return res;
  }
};
