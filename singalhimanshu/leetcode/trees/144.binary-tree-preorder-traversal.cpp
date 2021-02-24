/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> preorder;
    TreeNode *cur = root;
    stack<TreeNode *> s;
    while (!s.empty() || cur) {
      if (cur) {
        preorder.emplace_back(cur->val);
        s.emplace(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        cur = cur->right;
      }
    }
    return preorder;
  }
};
// @lc code=end
