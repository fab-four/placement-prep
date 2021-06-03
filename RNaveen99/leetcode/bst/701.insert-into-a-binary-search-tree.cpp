/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            root = new TreeNode(val);
        } else {
            insertIntoBSTutil(root, val);
        }
        return root;
    }
    void insertIntoBSTutil(TreeNode *root, int &val) {
        if (root->val > val) {
            if (root->left) {
                insertIntoBST(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if (root->right) {
                insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
    }
};