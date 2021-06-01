/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/k-closest-points-to-origin/
 */

struct comparator {
    bool operator()(vector<int> &p1, vector<int> &p2) {
        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
    }
};
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comparator> maxHeap;
        for (vector<int> ele : points) {
            maxHeap.emplace(ele);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while (maxHeap.size()) {
            result.emplace_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        selection(points, 0, points.size() - 1, k);
        vector<vector<int>> result(points.begin(), points.begin() + k);
        return result;
    }
    void selection(vector<vector<int>> &points, int left, int right, int k) {
        if (left >= right)
            return;

        int swaps = 0, i = left, index = left;
        for (; i < right; i++) {
            if (comparator(points[i], points[right])) {
                swap(points[i], points[index]);
                index++;
                swaps++;
            }
        }
        swap(points[index], points[right]);
        swaps++;
        if (swaps == k)
            return;
        if (swaps > k) {
            selection(points, left, index - 1, k);
        } else {
            selection(points, index + 1, right, k - swaps);
        }
    }
    bool comparator(vector<int> &p1, vector<int> &p2) {
        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
    }
};