/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-pruning/
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
    TreeNode *pruneTree(TreeNode *root) {
        if (pruneTreeUtil(root))
            return root;
        return nullptr;
    }
    int pruneTreeUtil(TreeNode *root) {
        if (!root)
            return 0;
        int left = pruneTreeUtil(root->left);
        int right = pruneTreeUtil(root->right);

        if (left == 0)
            root->left = nullptr;
        if (right == 0)
            root->right = nullptr;

        return left + right + (root->val == 1);
    }
};