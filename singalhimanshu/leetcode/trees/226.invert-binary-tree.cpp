// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/invert-binary-tree/

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
  TreeNode *invertTree(TreeNode *root) {
    return invertTreeBfs(root);
    // return invertTreeDfs(root);
    // return invertTreeRec(root);
  }

  TreeNode *invertTreeBfs(TreeNode *root) {
    if (root == nullptr) {
      return root;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
      swap(cur->left, cur->right);
    }
    return root;
  }

  TreeNode *invertTreeDfs(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();
      if (cur->left) {
        st.push(cur->left);
      }
      if (cur->right) {
        st.push(cur->right);
      }
      swap(cur->left, cur->right);
    }
    return root;
  }

  TreeNode *invertTreeRec(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    invertTreeRec(root->left);
    invertTreeRec(root->right);
    swap(root->left, root->right);
    return root;
  }
};
// @lc code=end
