// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
  Solution(vector<int> &nums) : m_nums(nums) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return m_nums; }

  /** Returns a random shuffling of the array. */
  // Fisher-Yates algorithm
  vector<int> shuffle() {
    vector<int> shuffled_nums(m_nums);
    for (int i = 0; i < shuffled_nums.size(); i++) {
      int rand_idx = i + rand() % (shuffled_nums.size() - i);
      swap(shuffled_nums[rand_idx], shuffled_nums[i]);
    }
    return shuffled_nums;
  }

private:
  vector<int> m_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
