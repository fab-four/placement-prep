/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode *root) {
        while (root) {
            if (root->left && root->right) {
                // attach the root->right to the preorder predecessor of root->right as right child
                TreeNode *temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                temp->right = root->right;
            }
            if (root->left) {
                root->right = root->left;
            }
            root->left = nullptr;
            root = root->right;
        }
    }
};