/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/binary-tree-paths/
 */

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
  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root)
      return {};
    vector<string> res;
    binaryTreePaths(root, to_string(root->val), res);
    return res;
  }
  void binaryTreePaths(TreeNode *root, string path, vector<string> &res) {
    if (!root->left && !root->right) {
      res.push_back(path);
      return;
    }
    if (root->left) {
      binaryTreePaths(root->left, path + "->" + to_string(root->left->val),
                      res);
    }
    if (root->right) {
      binaryTreePaths(root->right, path + "->" + to_string(root->right->val),
                      res);
    }
  }
};