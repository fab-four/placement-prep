/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        // base case : when key doesn't exists
        if (!root) {
            return nullptr;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        // We reach here when root is the node to be deleted.
        // If root has one children...either left or right
        if (!root->left) {
            return root->right;
        }
        if (!root->right) {
            return root->left;
        }
        // If root has both children
        TreeNode *parent = root;
        TreeNode *successor = root->right;
        // find inorder successor
        while (successor->left) {
            parent = successor;
            successor = successor->left;
        }
        if (parent == root) {
            parent->right = successor->right;
        } else {
            parent->left = successor->right;
        }
        root->val = successor->val;
        return root;
    }
};