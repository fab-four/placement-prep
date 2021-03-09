// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }
    int idx{0};
    return helper(preorder, idx, 0, preorder.size() - 1, mp);
  }

  TreeNode *helper(const vector<int> &preorder, int &idx, int st, int end,
                   const unordered_map<int, int> &mp) {
    if (st > end) {
      return nullptr;
    }
    TreeNode *root{new TreeNode(preorder[idx])};
    int cur_root_idx{mp.at(preorder[idx])};
    idx++;
    root->left = helper(preorder, idx, st, cur_root_idx - 1, mp);
    root->right = helper(preorder, idx, cur_root_idx + 1, end, mp);
    return root;
  }
};
// @lc code=end
