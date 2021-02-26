/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/binary-tree-inorder-traversal/
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
  vector<int> inorderTraversal(TreeNode *root) {
    // Recursive
    // if (!root)
    //   return {};

    // vector<int> l = inorderTraversal(root->left);
    // vector<int> r = inorderTraversal(root->right);
    // vector<int> res;
    // for (int &i : l) {
    //   res.push_back(i);
    // }
    // res.push_back(root->val);
    // for (int &i : r) {
    //   res.push_back(i);
    // }
    // return res;

    // Iterative 1
    // vector<int> res;
    // stack<TreeNode *> st;
    // while (root) {
    //   st.push(root);
    //   root = root->left;
    // }
    // while (!root && st.size()) {
    //   root = st.top();
    //   st.pop();
    //   res.push_back(root->val);
    //   root = root->right;
    //   while (root) {
    //     st.push(root);
    //     root = root->left;
    //   }
    // }
    // return res;

    // Iterative 2
    vector<int> res;
    stack<TreeNode *> st;
    while (root || st.size()) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val);
      root = node->right;
    }
    return res;
  }
};