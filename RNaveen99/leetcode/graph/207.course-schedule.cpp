/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/course-schedule/
 */

// DFS
class Solution {
    typedef vector<vector<int>> graph;

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> gray(numCourses, false);
        vector<bool> black(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!black[i] && !acyclic(g, gray, black, i)) {
                return false;
            }
        }
        return true;
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

    bool acyclic(graph &g, vector<bool> &gray, vector<bool> &black, int i) {
        gray[i] = true;
        for (int v : g[i]) {
            if (gray[v] && !black[v]) {
                // back-edge
                return false;
            }
            if (gray[v] && black[v]) {
                // forward-edge
                continue;
            }
            if (!acyclic(g, gray, black, v)) {
                return false;
            }
        }
        black[i] = true;
        return true;
    }
};

// DFS
class Solution {
    enum color { WHITE, GRAY, BLACK };
    typedef vector<vector<int>> graph;

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<color> visit(numCourses, WHITE);
        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == WHITE && !acyclic(g, visit, i)) {
                return false;
            }
        }
        return true;
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
        return true;
    }
};

// BFS
class Solution {
    typedef vector<vector<int>> graph;

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses, 0);
        graph g = buildGraph(numCourses, prerequisites, indegree);
        queue<int> q;

        // The first vertex in topological sorting is always a vertex with in-degree as 0.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            numCourses--;
            for (int v : g[front]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return numCourses == 0;
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