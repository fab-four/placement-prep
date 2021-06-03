/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/house-robber-iii/
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
  public:
    int rob(TreeNode *root) {
        vector<int> result = robUtil(root);
        return max(result[0], result[1]);
    }

    vector<int> robUtil(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }
        vector<int> leftProfit = robUtil(root->left);
        vector<int> rightProfit = robUtil(root->right);

        int rob = leftProfit[1] + root->val + rightProfit[1];
        int notRob = max(leftProfit[0], leftProfit[1]) + max(rightProfit[0], rightProfit[1]);

        return {rob, notRob};
    }
};