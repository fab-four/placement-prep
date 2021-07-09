/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int size = heights.size();
        vector<int> lessFromLeft(size, -1);
        for (int i = 1; i < size; i++) {
            int temp = i - 1;
            while (temp >= 0 && heights[temp] >= heights[i]) {
                temp = lessFromLeft[temp];
            }
            lessFromLeft[i] = temp;
        }
        vector<int> lessFromRight(size, size);
        for (int i = size - 2; i >= 0; i--) {
            int temp = i + 1;
            while (temp < size && heights[temp] >= heights[i]) {
                temp = lessFromRight[temp];
            }
            lessFromRight[i] = temp;
        }
        int maxArea = 0;
        for (int i = 0; i < size; i++) {
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }
        return maxArea;
    }
};

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int height = i == heights.size() ? 0 : heights[i];
            if (s.empty() || height >= heights[s.top()]) {
                s.emplace(i);
            } else {
                height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
                i--;
            }
        }
        return maxArea;
    }
};

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i <= heights.size(); i++) {
            if (!s.empty() && i < heights.size() && heights[i] == heights[s.top()]) {
                s.pop();
                s.emplace(i);
            }
            while (!s.empty() && isNewPillarOrReachEnd(heights, i, s.top())) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.emplace(i);
        }
        return maxArea;
    }
    bool isNewPillarOrReachEnd(vector<int> &heights, int i, int top) {
        if (i == heights.size()) {
            return true;
        }
        return heights[i] < heights[top];
    }
};
