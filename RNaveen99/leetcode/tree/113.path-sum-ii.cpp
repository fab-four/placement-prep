/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/path-sum-ii/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<int>> pathSums;
    vector<int> path;
    int tempSum = 0;

  public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        pathSumUtil(root, targetSum);
        return pathSums;
    }

    void pathSumUtil(TreeNode *root, int &targetSum) {
        if (!root)
            return;

        tempSum += root->val;
        path.emplace_back(root->val);
        if (!root->left && !root->right) {
            if (tempSum == targetSum) {
                pathSums.emplace_back(path);
            }
        } else {
            pathSumUtil(root->left, targetSum);
            pathSumUtil(root->right, targetSum);
        }
        tempSum -= root->val;
        path.pop_back();
    }
};