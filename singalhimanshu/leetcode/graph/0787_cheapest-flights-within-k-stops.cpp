// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

constexpr int mmax = numeric_limits<int>::max();

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    vector<int> dist(n, mmax);
    dist[src] = 0;
    for (int i = 0; i <= K; i++) {
      vector<int> temp(dist);
      for (const auto &flight : flights) {
        if (dist[flight[0]] != mmax) {
          temp[flight[1]] = min(temp[flight[1]], flight[2] + dist[flight[0]]);
        }
      }
      dist = move(temp);
    }
    return (dist[dst] == mmax) ? -1 : dist[dst];
  }
};
