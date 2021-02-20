// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    if (root == nullptr)
      return {};
    vector<int> inorder;
    stack<TreeNode *> s;
    TreeNode *temp_root = root;
    while (temp_root || !s.empty()) {
      if (temp_root) {
        s.emplace(temp_root);
        temp_root = temp_root->left;
      } else {
        temp_root = s.top();
        s.pop();
        inorder.emplace_back(temp_root->val);
        temp_root = temp_root->right;
      }
    }
    return inorder;
  }
};
