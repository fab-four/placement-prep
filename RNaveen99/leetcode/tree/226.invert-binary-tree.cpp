/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode *invertTree(TreeNode *root) {
        invertTreeUtil(root);
        return root;
    }
    void invertTreeUtil(TreeNode *root) {
        if (!root)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTreeUtil(root->left);
        invertTreeUtil(root->right);
    }
};