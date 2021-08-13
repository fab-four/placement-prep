class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  int numPairsDivisibleBy60(vector<int> &time) {
    int res = 0;
    vector<int> freq(60, 0);
    for (int t : time) {
      res += freq[(60 - t % 60) % 60];
      freq[t % 60]++;
    }
    return res;
  }
};
