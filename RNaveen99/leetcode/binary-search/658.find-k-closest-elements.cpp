/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-k-closest-elements/
 */

struct comparator {
    int x;
    comparator(int x) { this->x = x; }
    bool operator()(int &a, int &b) {
        if (abs(x - a) == abs(x - b)) {
            return a < b;
        }
        return abs(x - a) < abs(x - b);
    }
};

class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        sort(arr.begin(), arr.end(), comparator(x));
        vector<int> result(arr.begin(), arr.begin() + k);
        sort(result.begin(), result.end());
        return result;
    }
};

// binary search + sliding window
class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                break;
            }
            if (arr[mid] > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int leftPointer = mid - 1;
        int rightPointer = mid;
        while (rightPointer - leftPointer - 1 < k) {
            if (leftPointer == -1) {
                rightPointer++;
                continue;
            }
            if (rightPointer == arr.size()) {
                leftPointer--;
                continue;
            }
            if (abs(arr[leftPointer] - x) <= abs(arr[rightPointer] - x)) {
                leftPointer--;
            } else {
                rightPointer++;
            }
        }
        vector<int> result(arr.begin() + leftPointer + 1, arr.begin() + rightPointer);
        return result;
    }
};

class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        vector<int> result(arr.begin() + left, arr.begin() + left + k);
        return result;
    }
};