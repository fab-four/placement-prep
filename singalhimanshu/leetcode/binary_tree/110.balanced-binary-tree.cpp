// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/balanced-binary-tree/

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    int height_left = height(root->left);
    int height_right = height(root->right);
    return (abs(height_left - height_right) <= 1) && isBalanced(root->left) &&
           isBalanced(root->right);
  }

  int height(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    return 1 + max(height(node->left), height(node->right));
  }
};
// @lc code=end
