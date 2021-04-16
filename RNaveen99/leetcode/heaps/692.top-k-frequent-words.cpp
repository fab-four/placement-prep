/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/top-k-frequent-words/
 */

class Solution {
  public:
    struct comparator {
        int operator()(pair<string, int> &a, pair<string, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> m;
        for (string ele : words) {
            m[ele]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;

        for (auto ele : m) {
            pq.emplace(ele);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> answer;
        while (k--) {
            answer.emplace_back(pq.top().first);
            pq.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};