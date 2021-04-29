// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int q_size = q.size();
      double avg = 0;
      for (int i = 0; i < q_size; i++) {
        TreeNode *cur = q.front();
        avg += cur->val;
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
        q.pop();
      }
      res.emplace_back(avg / (double)q_size);
    }
    return res;
  }
};
