/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */
// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/diameter-of-binary-tree/

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
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    auto result = fastDiameter(root);
    return result.second;
  }

  // {height, diameter}
  pair<int, int> fastDiameter(TreeNode *root) {
    if (root == nullptr) {
      return {0, 0};
    }
    auto left_info = fastDiameter(root->left);
    auto right_info = fastDiameter(root->right);
    int cur_height = 1 + max(left_info.first, right_info.first);
    int cur_diameter = max(left_info.first + right_info.first,
                           max(left_info.second, right_info.second));
    return {cur_height, cur_diameter};
  }
};
// @lc code=end
