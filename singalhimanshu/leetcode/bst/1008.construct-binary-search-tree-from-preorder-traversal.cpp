// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
constexpr int mmax = numeric_limits<int>::max();

class Solution {
  size_t idx = 0;

public:
  TreeNode *bstFromPreorder(vector<int> &preorder, int parent_val = mmax) {
    if (preorder.size() <= idx || preorder[idx] > parent_val) {
      return nullptr;
    }
    auto new_node = new TreeNode(preorder[idx]);
    idx++;
    new_node->left = bstFromPreorder(preorder, new_node->val);
    new_node->right = bstFromPreorder(preorder, parent_val);
    return new_node;
  }
};
// @lc code=end
