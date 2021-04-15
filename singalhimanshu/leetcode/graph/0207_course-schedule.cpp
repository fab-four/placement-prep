// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/course-schedule/

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &pres) {
    auto adj_list = buildGraph(numCourses, pres);
    return hasCycleBfs(adj_list);
    // return hasCycleDfs(adj_list, );
  }

  bool hasCycleBfs(const vector<vector<int>> &adj_list) {
    auto indegree = getIndegree(adj_list);
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    int course_count = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      course_count++;
      for (const auto &neigh : adj_list[cur]) {
        indegree[neigh]--;
        if (indegree[neigh] == 0) {
          q.push(neigh);
        }
      }
    }
    return (course_count == adj_list.size());
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
