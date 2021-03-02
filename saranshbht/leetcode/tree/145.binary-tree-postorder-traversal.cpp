/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/binary-tree-postorder-traversal/
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
  vector<int> postorderTraversal(TreeNode *root) {
    // Recursive
    // if (!root)
    //   return {};
    // vector<int> res;
    // vector<int> l = postorderTraversal(root->left);
    // vector<int> r = postorderTraversal(root->right);
    // for (auto &i : l)
    //   res.push_back(i);
    // for (auto &i : r)
    //   res.push_back(i);
    // res.push_back(root->val);
    // return res;

    // Iterative 1
    vector<int> res;
    stack<pair<TreeNode *, bool>> st;
    if (root)
      st.push({root, false});
    while (st.size()) {
      pair<TreeNode *, bool> &node = st.top();
      if (node.second) {
        res.push_back(node.first->val);
        st.pop();
      } else {
        node.second = true;
        if (node.first->right)
          st.push({node.first->right, false});
        if (node.first->left)
          st.push({node.first->left, false});
      }
    }
    return res;

    // Works here but won't work for every use case
    // https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization/743080
    // Iterative 2
    // vector<int> res;
    // stack<TreeNode *> st;
    // if (root)
    //   st.push(root);
    // while (st.size()) {
    //   TreeNode *node = st.top();
    //   st.pop();
    //   res.push_back(node->val);
    //   if (node->left)
    //     st.push(node->left);
    //   if (node->right)
    //     st.push(node->right);
    // }
    // reverse(res.begin(), res.end());
    // return res;
  }
};
