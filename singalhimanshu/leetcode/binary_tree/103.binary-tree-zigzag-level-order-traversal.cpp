// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    TreeNode *cur = root;
    queue<TreeNode *> q;
    q.push(cur);
    bool left_to_right = true;
    vector<vector<int>> zigzag;
    while (!q.empty()) {
      size_t q_size = q.size();
      vector<int> cur_level_ele(q_size);
      for (size_t i = 0; i < q_size; i++) {
        cur = q.front();
        q.pop();
        size_t idx = left_to_right ? i : (q_size - i - 1);
        cur_level_ele[idx] = cur->val;
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      left_to_right = !left_to_right;
      zigzag.emplace_back(std::move(cur_level_ele));
    }
    return zigzag;
  }
};
// @lc code=end
