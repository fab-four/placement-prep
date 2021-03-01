// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start

constexpr int my_min = numeric_limits<int>::min();
constexpr int my_max = numeric_limits<int>::max();

struct Entry {
  int val;
  int row;
  int col;
  Entry(int val, int row, int col) : val(val), row(row), col(col) {}
};

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    size_t nums_size{nums.size()};
    auto comp = [](Entry e1, Entry e2) { return e1.val > e2.val; };
    priority_queue<Entry, vector<Entry>, decltype(comp)> pq(comp);
    int cur_max{my_min}, cur_min{my_max};
    size_t cur_col{0};
    for (size_t row = 0; row < nums_size; row++) {
      pq.push(Entry(nums[row][cur_col], row, cur_col));
      cur_max = max(cur_max, nums[row][cur_col]);
      cur_min = min(cur_min, nums[row][cur_col]);
    }
    int min_range_min{cur_min};
    int min_range_max{cur_max};
    while (!pq.empty()) {
      Entry cur_min_entry{pq.top()};
      pq.pop();
      cur_col = cur_min_entry.col + 1;
      if (cur_col >= nums[cur_min_entry.row].size()) {
        break;
      }
      int next_val{nums[cur_min_entry.row][cur_col]};
      pq.push(Entry(next_val, cur_min_entry.row, cur_col));
      cur_max = max(cur_max, next_val);
      cur_min = pq.top().val;
      if (min_range_max - min_range_min > cur_max - cur_min) {
        min_range_min = cur_min;
        min_range_max = cur_max;
      }
    }
    return {min_range_min, min_range_max};
  }
};
// @lc code=end