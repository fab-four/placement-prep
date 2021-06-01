/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/number-of-recent-calls/
 */

// sliding window
class RecentCounter {
    queue<int> q;
    int counter = 0;

  public:
    RecentCounter() {}

    int ping(int t) {
        q.emplace(t);
        counter++;
        while (!q.empty() && t - q.front() > 3000) {
            q.pop();
            counter--;
        }
        return counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */