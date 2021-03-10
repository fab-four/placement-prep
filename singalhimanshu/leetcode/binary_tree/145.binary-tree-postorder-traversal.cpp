// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> post_order;
    TreeNode *cur = root;
    stack<TreeNode *> st;
    TreeNode *child = nullptr;
    while (cur || !st.empty()) {
      if (cur) {
        st.push(cur);
        cur = cur->left;
      } else {
        auto temp = st.top();
        if (temp->right && child != temp->right) {
          cur = temp->right;
        } else {
          child = temp;
          post_order.emplace_back(temp->val);
          st.pop();
        }
      }
    }
    return post_order;
  }
};
// @lc code=end
