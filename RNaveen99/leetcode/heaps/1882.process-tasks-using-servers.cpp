/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/process-tasks-using-servers/
 */

class Solution {
    typedef pair<int, int> p;

  public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        // <weight, index>
        priority_queue<p, vector<p>, greater<p>> free_servers;
        // <freeTime, index>
        priority_queue<p, vector<p>, greater<p>> busy_servers;

        vector<int> ans(tasks.size());

        for (int i = 0; i < servers.size(); i++) {
            free_servers.emplace(servers[i], i);
        }

        long time = 0;
        for (int i = 0; i < tasks.size(); i++) {
            time = i > time ? i : time;
            if (free_servers.empty() && busy_servers.top().first > time) {
                time = busy_servers.top().first;
            }

            while (!busy_servers.empty() && busy_servers.top().first <= time) {
                auto &top = busy_servers.top();
                free_servers.emplace(servers[top.second], top.second);
                busy_servers.pop();
            }

            auto &top = free_servers.top();
            busy_servers.emplace(time + tasks[i], top.second);
            ans[i] = top.second;
            free_servers.pop();
        }
        return ans;
    }
};