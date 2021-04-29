// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/path-sum/

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
  // Time Complexity : O(n)
  // Space Complexity : O(log(n))
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if ((targetSum == root->val) && (root->left == nullptr) &&
        (root->right == nullptr)) {
      return true;
    }
    targetSum -= root->val;
    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
  }
};
