// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

constexpr int mmin = std::numeric_limits<int>::min();

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int max_sum = mmin;
    helper(root, max_sum);
    return max_sum;
  }

  int helper(TreeNode *node, int &max_sum) {
    if (node == nullptr) {
      return 0;
    }
    int left_sum = max(0, helper(node->left, max_sum));
    int right_sum = max(0, helper(node->right, max_sum));
    max_sum = max(max_sum, left_sum + right_sum + node->val);
    return node->val + max(left_sum, right_sum);
  }
};
// @lc code=end
