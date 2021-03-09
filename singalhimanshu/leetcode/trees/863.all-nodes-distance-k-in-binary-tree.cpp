// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    vector<int> result;
    printAtDistK(root, target, K, result);
    return result;
  }

  int printAtDistK(TreeNode *node, TreeNode *target, int k,
                   vector<int> &result) {
    if (node == nullptr) {
      return -1;
    }
    if (node == target) {
      printAtLevelK(node, k, result);
      return 0;
    }
    int left_dist = printAtDistK(node->left, target, k, result);
    if (left_dist != -1) {
      if (left_dist + 1 == k) {
        result.emplace_back(node->val);
      } else {
        printAtLevelK(node->right, k - 2 - left_dist, result);
      }
      return left_dist + 1;
    }
    int right_dist = printAtDistK(node->right, target, k, result);
    if (right_dist != -1) {
      if (right_dist + 1 == k) {
        result.emplace_back(node->val);
      } else {
        printAtLevelK(node->left, k - 2 - right_dist, result);
      }
      return right_dist + 1;
    }
    return -1;
  }

  void printAtLevelK(TreeNode *node, int k, vector<int> &result) {
    if (node == nullptr || k < 0) {
      return;
    }
    if (k == 0) {
      result.emplace_back(node->val);
      return;
    }
    printAtLevelK(node->left, k - 1, result);
    printAtLevelK(node->right, k - 1, result);
  }
};
// @lc code=end
