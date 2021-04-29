// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
  // Space Complexity : O(n)
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);
    if (left_depth == 0 && right_depth == 0) {
      return 0;
    }
    if (left_depth == 0) {
      left_depth = INT_MAX;
    }
    if (right_depth == 0) {
      right_depth = INT_MAX;
    }
    return 1 + min(left_depth, right_depth);
  }
};
