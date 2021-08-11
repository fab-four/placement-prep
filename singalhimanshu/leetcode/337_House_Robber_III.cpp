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
  // Time Complexity: O(n), where n is the number of houses
  // Space Complexity: O(h), because of the recursion stack
  int rob(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    pair<int, int> res = robUtil(root);
    return max(res.first, res.second);
  }

  // {not_robbed, robbed}
  pair<int, int> robUtil(TreeNode *root) {
    if (root == nullptr) {
      return {0, 0};
    }
    pair<int, int> left = robUtil(root->left);
    pair<int, int> right = robUtil(root->right);
    pair<int, int> res;
    res.first = max(left.first, left.second) + max(right.first, right.second);
    res.second = root->val + left.first + right.first;
    return res;
  }

  // Time Complexity: Exponential
  int robRec(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int rob_cur = root->val;
    if (root->left) {
      rob_cur += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      rob_cur += rob(root->right->left) + rob(root->right->right);
    }
    return max(rob_cur, rob(root->left) + rob(root->right));
  }
};
