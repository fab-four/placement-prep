/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/combination-sum/
 */

class Solution {
    vector<vector<int>> allCombinations;
    vector<int> combination;

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        combineUtil(candidates, 0, target);
        return allCombinations;
    }

    void combineUtil(vector<int> &candidates, int start, int target) {
        if (target == 0) {
            allCombinations.emplace_back(combination);
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++) {
            combination.emplace_back(candidates[i]);
            combineUtil(candidates, i, target - candidates[i]);
            combination.pop_back();
        }
    }
};