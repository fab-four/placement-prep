// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/validate-binary-search-tree/

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

constexpr long mn = numeric_limits<long>::min();
constexpr long mx = numeric_limits<long>::max();

class Solution {
public:
  bool isValidBST(TreeNode *root) { return helper(root); }

  bool helper(TreeNode *root, long m_min = mn, long m_max = mx) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= m_min || root->val >= m_max) {
      return false;
    }
    return helper(root->left, m_min, root->val) &&
           helper(root->right, root->val, m_max);
  }
};
