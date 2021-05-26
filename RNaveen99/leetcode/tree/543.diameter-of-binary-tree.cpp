/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameter = 0;

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        diameterUtil(root);
        return diameter;
    }

    int diameterUtil(TreeNode *root) {
        if (!root)
            return 0;

        int left = diameterUtil(root->left);
        int right = diameterUtil(root->right);

        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }
};