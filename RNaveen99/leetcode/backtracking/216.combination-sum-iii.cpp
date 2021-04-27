/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/combination-sum-iii/
 */

class Solution {
    vector<vector<int>> allCombinations;
    vector<int> combination;

  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        combineUtil(n, k, 1);
        return allCombinations;
    }

    void combineUtil(int target, int k, int start) {
        if (target == 0 && combination.size() == k) {
            allCombinations.emplace_back(combination);
        }
        if (target < 0)
            return;
        for (int i = start; i <= 9; i++) {
            combination.emplace_back(i);
            combineUtil(target - i, k, i + 1);
            combination.pop_back();
        }
    }
};