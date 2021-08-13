class Solution {
public:
  // Time Complexity: O(n log(n))
  // Space Complexity: O(n)
  vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> temp(arr);
    sort(begin(temp), end(temp));
    unordered_map<int, int> rank_mp;
    int rank = 1;
    for (int t : temp) {
      if (rank_mp.find(t) == end(rank_mp)) {
        rank_mp[t] = rank++;
      }
    }
    vector<int> ranks(arr.size());
    for (int i = 0; i < arr.size(); i++) {
      ranks[i] = rank_mp[arr[i]];
    }
    return ranks;
  }
};
