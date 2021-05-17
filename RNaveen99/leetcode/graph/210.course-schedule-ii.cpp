/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/course-schedule-ii/
 */

// DFS
class Solution {
    vector<int> result;
    int index;
    enum color { WHITE, GRAY, BLACK };
    typedef vector<vector<int>> graph;

  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        result = vector<int>(numCourses);
        index = numCourses - 1;
        graph g = buildGraph(numCourses, prerequisites);
        vector<color> visit(numCourses, WHITE);
        bool flag = true;
        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == WHITE && !acyclic(g, visit, i)) {
                flag = false;
                break;
            }
        }
        if (!flag)
            result.clear();
        return result;
    }
    graph buildGraph(int numCourses, graph &prerequisites) {
        graph g(numCourses);
        for (auto coursePair : prerequisites) {
            int before = coursePair[1];
            int after = coursePair[0];
            g[before].emplace_back(after);
        }
        return g;
    }

    bool acyclic(graph &g, vector<color> &visit, int i) {
        visit[i] = GRAY;
        for (int v : g[i]) {
            if (visit[v] == GRAY) {
                // back-edge
                return false;
            }
            if (visit[v] == BLACK) {
                // forward-edge
                continue;
            }
            if (!acyclic(g, visit, v)) {
                return false;
            }
        }
        visit[i] = BLACK;
        result[index--] = i;
        return true;
    }
};

// BFS
class Solution {
    typedef vector<vector<int>> graph;

  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses, 0);
        graph g = buildGraph(numCourses, prerequisites, indegree);
        queue<int> q;

        // The first vertex in topological sorting is always a vertex with in-degree as 0.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            numCourses--;
            result.emplace_back(front);
            for (int v : g[front]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (numCourses) {
            result.clear();
        }
        return result;
    }
    graph buildGraph(int numCourses, graph &prerequisites, vector<int> &indegree) {
        graph g(numCourses);
        for (auto coursePair : prerequisites) {
            int before = coursePair[1];
            int after = coursePair[0];
            g[before].emplace_back(after);
            indegree[after]++;
        }
        return g;
    }
};