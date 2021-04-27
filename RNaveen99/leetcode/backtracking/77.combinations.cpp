/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/combinations/
 */

// similar to subsets .... but all subsets of size k (k <= n)
class Solution {
    vector<vector<int>> allCombinations;

  public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        combineUtil(n, 1, combination, k);
        return allCombinations;
    }
    void combineUtil(int n, int start, vector<int> &combination, int k) {
        if (combination.size() == k) {
            allCombinations.emplace_back(combination);
        }
        for (int i = start; i <= n; i++) {
            combination.emplace_back(i);
            combineUtil(n, i + 1, combination, k);
            combination.pop_back();
        }
    }
};

class Solution {
    vector<vector<int>> allCombinations;

  public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        combineUtil(n, 1, combination, k);
        return allCombinations;
    }
    void combineUtil(int n, int start, vector<int> &combination, int k) {
        if (combination.size() == k) {
            allCombinations.emplace_back(combination);
            return;
        }
        if (start <= n) {
            combination.emplace_back(start);
            combineUtil(n, start + 1, combination, k);
            combination.pop_back();
            combineUtil(n, start + 1, combination, k);
        }
    }
};

class Solution {
    vector<vector<int>> allCombinations;

  public:
    vector<vector<int>> combine(int n, int k) {
        for (int i = 0; i < 1 << n; i++) {
            vector<int> combination;
            for (int j = 0; j < n && combination.size() <= k; j++) {
                if (i & (1 << j)) {
                    combination.emplace_back(j + 1);
                }
            }
            if (combination.size() == k) {
                allCombinations.emplace_back(combination);
            }
        }
        return allCombinations;
    }
};