// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/subtree-of-another-tree/

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
  // Time Complexity : O(m * n)
  // Space Complexity : O(m + n)
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == nullptr) {
      return false;
    }
    if (isSame(s, t)) {
      return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool isSame(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    if (s->val != t->val) {
      return false;
    }
    return isSame(s->left, t->left) && isSame(s->right, t->right);
  }
};
