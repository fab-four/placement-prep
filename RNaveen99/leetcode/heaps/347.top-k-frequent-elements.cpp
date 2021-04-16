/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/top-k-frequent-elements/
 */

class Solution {
  public:
    struct comparator {
        int operator()(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        if (k == nums.size())
            return nums;
        map<int, int> frequency;
        for (int ele : nums) {
            frequency[ele]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

        for (auto ele : frequency) {
            pq.emplace(ele);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> answer;
        while (pq.size()) {
            answer.emplace_back(pq.top().first);
            pq.pop();
        }
        return answer;
    }
};

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        if (k == nums.size())
            return nums;
        map<int, int> frequency;
        for (int ele : nums) {
            frequency[ele]++;
        }

        vector<pair<int, int>> mappings(frequency.begin(), frequency.end());

        selection(mappings, 0, mappings.size() - 1, k);
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.emplace_back(mappings[i].first);
        }
        return answer;
    }

    void selection(vector<pair<int, int>> &mappings, int left, int right, int k) {
        if (left >= right)
            return;

        int swaps = 0, i = left, index = left;
        for (; i < right; i++) {
            if (mappings[i].second > mappings[right].second) {
                swap(mappings[i], mappings[index]);
                index++;
                swaps++;
            }
        }
        swap(mappings[index], mappings[right]);
        swaps++;
        if (swaps == k)
            return;
        if (swaps > k) {
            selection(mappings, left, index - 1, k);
        } else {
            selection(mappings, index + 1, right, k - swaps);
        }
    }
};