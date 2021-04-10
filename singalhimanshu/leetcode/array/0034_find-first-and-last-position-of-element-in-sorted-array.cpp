class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result(2);
    result[0] = firstOcc(nums, target);
    result[1] = lastOcc(nums, target);
    return result;
  }

  int firstOcc(const vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    int first_idx = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        first_idx = mid;
        high = mid - 1;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return first_idx;
  }

  int lastOcc(const vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    int last_idx = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        last_idx = mid;
        low = mid + 1;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return last_idx;
  }
};
