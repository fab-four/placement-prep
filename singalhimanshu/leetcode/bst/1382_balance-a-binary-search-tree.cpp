// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/balance-a-binary-search-tree/

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
  TreeNode *balanceBST(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    vector<TreeNode *> inorder;
    inorderTrav(root, inorder);
    return buildBSTFromSortedArray(0, inorder.size() - 1, inorder);
  }

  TreeNode *buildBSTFromSortedArray(int left, int right,
                                    const vector<TreeNode *> &inorder) {
    if (left > right) {
      return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode *cur_node = inorder[mid];
    cur_node->left = buildBSTFromSortedArray(left, mid - 1, inorder);
    cur_node->right = buildBSTFromSortedArray(mid + 1, right, inorder);
    return cur_node;
  }

  void inorderTrav(TreeNode *root, vector<TreeNode *> &inorder) {
    if (root == nullptr) {
      return;
    }
    inorderTrav(root->left, inorder);
    inorder.emplace_back(root);
    inorderTrav(root->right, inorder);
  }
};
