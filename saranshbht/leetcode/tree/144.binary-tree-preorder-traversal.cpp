/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/binary-tree-preorder-traversal/
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
  vector<int> preorderTraversal(TreeNode *root) {
    // Recursive
    // if (!root)
    //     return {};
    // vector<int> res;
    // res.push_back(root -> val);

    // vector<int> l = preorderTraversal(root -> left);
    // vector<int> r = preorderTraversal(root -> right);
    // for (auto &i : l)
    //     res.push_back(i);
    // for (auto &i : r)
    //     res.push_back(i);
    // return res;

    // Iterative
    if (!root)
      return {};
    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while (st.size()) {
      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val);
      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return res;
  }
};