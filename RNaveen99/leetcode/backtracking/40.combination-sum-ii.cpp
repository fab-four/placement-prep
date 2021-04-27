/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/combination-sum-ii/
 */

class Solution {
    vector<vector<int>> allCombinations;
    vector<int> combination;

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            combination.emplace_back(candidates[i]);
            combineUtil(candidates, i + 1, target - candidates[i]);
            combination.pop_back();
        }
    }
};