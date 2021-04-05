// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    int min_val = min(p->val, q->val);
    int max_val = max(p->val, q->val);
    if (root->val > max_val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < min_val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    return root;
  }
};
// @lc code=end
