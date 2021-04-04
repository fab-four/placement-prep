// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/delete-node-in-a-bst/

/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val == key) {
      if (root->right == nullptr) {
        return root->left;
      }
      TreeNode *temp = root->right;
      while (temp->left) {
        temp = temp->left;
      }
      swap(temp->val, root->val);
      root->right = deleteNode(root->right, key);
      return root;
    }
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
};
// @Lc Code=end
