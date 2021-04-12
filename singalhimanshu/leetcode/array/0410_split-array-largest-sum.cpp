// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int low = *max_element(begin(nums), end(nums));
    int high = accumulate(begin(nums), end(nums), 0);
    int ans = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (isValid(nums, m, mid)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }

  bool isValid(const vector<int> &nums, int m, int max_sum) {
    int cur_sum = 0;
    int splits = 1;
    for (const auto &ele : nums) {
      cur_sum += ele;
      if (cur_sum > max_sum) {
        cur_sum = ele;
        splits++;
      }
      if (splits > m) {
        return false;
      }
    }
    return true;
  }
};
