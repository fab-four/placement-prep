/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 */

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = matrix[0][0];
        int right = matrix[rows - 1][cols - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;

            // count is the number of elements less or equal to mid
            int count = countLessThanEqual(matrix, mid);

            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int countLessThanEqual(vector<vector<int>> &matrix, int mid) {
        int row = matrix.size() - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};

// calculate new lower & upper bound
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = matrix[0][0];
        int right = matrix[rows - 1][cols - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;

            int minimum = left;
            int maximum = right;
            // count is the number of elements less or equal to mid
            int count = countLessThanEqual(matrix, mid, minimum, maximum);

            if (count == k) {
                return minimum;
            }
            if (count < k) {
                left = maximum;
            } else {
                right = minimum;
            }
        }
        return left;
    }

    int countLessThanEqual(vector<vector<int>> &matrix, int mid, int &minimum, int &maximum) {
        int row = matrix.size() - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] <= mid) {
                minimum = max(minimum, matrix[row][col]);
                count += row + 1;
                col++;
            } else {
                maximum = min(maximum, matrix[row][col]);
                row--;
            }
        }
        return count;
    }
};

class Solution {
  public:
    struct comparator {
        int operator()(vector<int> &a, vector<int> &b) { return a[0] > b[0]; }
    };
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<vector<int>, vector<vector<int>>, comparator> minHeap;

        for (int i = 0; i < rows && i < k; i++) {
            vector<int> a = {matrix[i][0], i, 0};
            minHeap.emplace(a);
        }
        while (--k) {
            vector<int> top = minHeap.top();
            minHeap.pop();
            if (top[2] + 1 < cols) {
                vector<int> a = {matrix[top[1]][top[2] + 1], top[1], top[2] + 1};
                minHeap.emplace(a);
            }
        }
        return minHeap.top()[0];
    }
};