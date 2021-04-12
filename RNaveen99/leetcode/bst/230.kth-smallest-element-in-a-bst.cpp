/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode *root, int k) { return kthsmallestUtil(root, k); }

    int kthsmallestUtil(TreeNode *root, int &k) {
        if (!root) {
            return -1;
        }
        int left = kthsmallestUtil(root->left, k);
        if (left != -1) {
            return left;
        }
        if (--k == 0) {
            return root->val;
        }

        int right = kthsmallestUtil(root->right, k);
        if (right != -1) {
            return right;
        }
        return -1;
    }
};