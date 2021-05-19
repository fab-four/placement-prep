/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
 */

pair<int, int> bfs(vector<vector<int>> &graph, int root, int depth = 0) {
    int len = 0, node = root;
    int n = graph.size();

    vector<int> distance(n);
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(root);
    visited[root] = true;
    distance[root] = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto ele : graph[front]) {
            if (!visited[ele]) {
                distance[ele] = distance[front] + 1;
                visited[ele] = true;
                q.push(ele);
                if (distance[ele] > len) {
                    len = distance[ele];
                    node = ele;
                }
            }
        }
    }
    return {node, len};
}

int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) {
        return 0;
    }
    vector<vector<int>> graph(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            root = i;
        } else {
            graph[i].push_back(arr[i]);
            graph[arr[i]].push_back(i);
        }
    }
    // calcluate farthest node(n1) from root
    pair<int, int> n1 = bfs(graph, root);

    // calcluate farthest node(n2) from node(n1)
    return bfs(graph, n1.first).second;
}