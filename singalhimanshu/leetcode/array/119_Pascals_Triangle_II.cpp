class Solution {
public:
  // Time Complexity: O(row_idx)
  // Space Complexity: O(row_idx)
  vector<int> getRow(int row_idx) {
    vector<int> res(1, 1);
    res.reserve(row_idx + 1);
    for (int i = 1; i <= row_idx; i++) {
      for (int j = res.size() - 1; j > 0; j--) {
        res[j] += res[j - 1];
      }
      res.push_back(1);
    }
    return res;
  }
};
