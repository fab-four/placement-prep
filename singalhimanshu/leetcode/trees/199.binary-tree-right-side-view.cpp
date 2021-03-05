// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/binary-tree-right-side-view/

/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    TreeNode *cur = root;
    queue<TreeNode *> q;
    q.push(cur);
    vector<int> right_side_view;
    while (!q.empty()) {
      auto q_size = q.size();
      for (size_t i = 0; i < q_size; i++) {
        cur = q.front();
        q.pop();
        if (i == q_size - 1) {
          right_side_view.emplace_back(cur->val);
        }
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
    }
    return right_side_view;
  }
};
// @lc code=end
