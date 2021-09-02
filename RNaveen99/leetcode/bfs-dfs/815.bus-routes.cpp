/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/bus-routes/
 */

class Solution {
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        unordered_map<int, vector<int>> routesToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                routesToBus[routes[i][j]].emplace_back(i);
            }
        }
        queue<pair<int, int>> q;
        q.emplace(source, 0);
        unordered_set<int> visitedRoutes;
        visitedRoutes.emplace(source);

        while (!q.empty()) {
            auto [route, interchange] = q.front();
            q.pop();
            if (route == target) {
                return interchange;
            }
            for (int &bus : routesToBus[route]) {
                for (int &eachRoute : routes[bus]) {
                    if (!visitedRoutes.count(eachRoute)) {
                        q.emplace(eachRoute, interchange + 1);
                        visitedRoutes.emplace(route);
                    }
                }
                routes[bus].clear();
            }
        }
        return -1;
    }
};

class Solution {
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        unordered_map<int, vector<int>> routesToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                routesToBus[routes[i][j]].emplace_back(i);
            }
        }
        queue<int> q;
        q.emplace(source);
        int interchange = 0;
        unordered_set<int> visitedRoutes;
        visitedRoutes.emplace(source);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int route = q.front();
                q.pop();
                if (route == target) {
                    return interchange;
                }
                for (int &bus : routesToBus[route]) {
                    for (int &eachRoute : routes[bus]) {
                        if (!visitedRoutes.count(eachRoute)) {
                            q.emplace(eachRoute);
                            visitedRoutes.emplace(route);
                        }
                    }
                    routes[bus].clear();
                }
            }
            interchange++;
        }
        return -1;
    }
};