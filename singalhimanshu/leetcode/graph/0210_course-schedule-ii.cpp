// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
  vector<int> findOrder(int num_courses, vector<vector<int>> &prerequisites) {
    auto adj_list = buildGraph(num_courses, prerequisites);
    return courseOrdering(adj_list);
  }
  vector<int> courseOrdering(const vector<vector<int>> &adj_list) {
    auto indegree = getIndegree(adj_list);
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> ordering;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      ordering.emplace_back(cur);
      for (const auto &neigh : adj_list[cur]) {
        indegree[neigh]--;
        if (indegree[neigh] == 0) {
          q.push(neigh);
        }
      }
    }
    if (ordering.size() < adj_list.size()) {
      return {};
    }
    reverse(begin(ordering), end(ordering));
    return ordering;
  }

  vector<int> getIndegree(const vector<vector<int>> &adj_list) {
    vector<int> indegree(adj_list.size());
    for (const auto &ver : adj_list) {
      for (const auto &neigh : ver) {
        indegree[neigh]++;
      }
    }
    return indegree;
  }

  vector<vector<int>> buildGraph(int num_courses,
                                 const vector<vector<int>> &pres) {
    vector<vector<int>> adj_list(num_courses);
    for (const auto &pre : pres) {
      adj_list[pre[0]].emplace_back(pre[1]);
    }
    return adj_list;
  }
};
