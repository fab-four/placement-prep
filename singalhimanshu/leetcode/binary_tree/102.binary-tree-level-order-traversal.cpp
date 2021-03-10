// @author: Himanshu
// @user: singalhimanshu
// https://leetcode.com/problems/binary-tree-level-order-traversal/
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    TreeNode *cur = root;
    vector<vector<int>> level_order;
    queue<TreeNode *> q;
    q.emplace(cur);
    while (!q.empty()) {
      size_t q_size = q.size();
      vector<int> cur_level_val;
      cur_level_val.reserve(q_size);
      for (size_t i = 0; i < q_size; i++) {
        TreeNode *front = q.front();
        q.pop();
        if (front->left)
          q.emplace(front->left);
        if (front->right)
          q.emplace(front->right);
        cur_level_val.emplace_back(front->val);
      }
      level_order.emplace_back(std::move(cur_level_val));
    }
    return level_order;
  }
};
// @lc code=end
