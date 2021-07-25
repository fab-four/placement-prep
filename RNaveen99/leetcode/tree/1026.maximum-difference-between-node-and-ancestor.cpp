/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    int maxAncestorDiff(TreeNode *root) { return maxDiffUtil(root, INT_MIN, INT_MAX); }
    int maxDiffUtil(TreeNode *root, int maxNode, int minNode) {
        if (!root) {
            return maxNode - minNode;
        }
        maxNode = max(maxNode, root->val);
        minNode = min(minNode, root->val);

        int leftDiff = maxDiffUtil(root->left, maxNode, minNode);
        int rightDiff = maxDiffUtil(root->right, maxNode, minNode);
        return max(leftDiff, rightDiff);
    }
};