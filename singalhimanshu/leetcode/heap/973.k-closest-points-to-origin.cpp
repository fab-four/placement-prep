// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/k-closest-points-to-origin/

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;
    for (int i = 0; i < points.size(); i++) {
      pq.push({euclideanDistance(points[i][0], points[i][1]), i});
    }
    vector<vector<int>> result;
    result.reserve(k);
    while (!pq.empty() && k--) {
      auto p = pq.top();
      pq.pop();
      vector<int> temp{points[p.second][0], points[p.second][1]};
      result.emplace_back(move(temp));
    }
    return result;
  }

  double euclideanDistance(int x, int y) { return sqrt((x * x) + (y * y)); }
};
// @lc code=end
