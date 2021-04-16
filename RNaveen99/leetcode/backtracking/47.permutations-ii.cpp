/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/permutations-ii/
 */

class Solution {
  private:
    vector<vector<int>> permutations;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        allPermutations(nums, 0, nums.size());
        return permutations;
    }

    void allPermutations(vector<int> &nums, int left, int right) {
        if (left == right) {
            permutations.push_back(nums);
            return;
        }

        for (int i = left; i < right; i++) {
            if (!shouldSwap(nums, left, i))
                continue;
            swap(nums[i], nums[left]);
            allPermutations(nums, left + 1, right);
            swap(nums[i], nums[left]);
        }
    }
    bool shouldSwap(vector<int> &nums, int left, int current) {
        for (int i = left; i < current; i++) {
            if (nums[i] == nums[current]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
  private:
    vector<vector<int>> permutations;
    unordered_map<int, int> m;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        for (int ele : nums) {
            m[ele]++;
        }
        vector<int> temp;
        int size = nums.size();
        allPermutations(temp, size);
        return permutations;
    }

    void allPermutations(vector<int> &temp, int &size) {
        if (temp.size() == size) {
            permutations.push_back(temp);
            return;
        }

        for (auto itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second > 0) {
                temp.emplace_back(itr->first);
                itr->second--;
                allPermutations(temp, size);
                itr->second++;
                temp.pop_back();
            }
        }
    }
};

class Solution {
  private:
    vector<vector<int>> permutations;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        allPermutations(nums, 0);
        return permutations;
    }

    void allPermutations(vector<int> &nums, int left) {
        if (left == nums.size()) {
            permutations.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for (int i = left; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);
            swap(nums[i], nums[left]);
            allPermutations(nums, left + 1);
            swap(nums[i], nums[left]);
        }
    }
};

class Solution {
  private:
    vector<vector<int>> permutations;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        allPermutations(nums, 0);
        return permutations;
    }

    void allPermutations(vector<int> &nums, int left) {
        if (left == nums.size()) {
            permutations.push_back(nums);
            return;
        }

        for (int i = left; i < nums.size(); i++) {
            if (i > left && nums[i] == nums[left])
                continue;
            swap(nums[i], nums[left]);
            allPermutations(nums, left + 1);
        }

        for (int i = nums.size() - 1; i > left; i--) {
            swap(nums[i], nums[left]);
        }
    }
};