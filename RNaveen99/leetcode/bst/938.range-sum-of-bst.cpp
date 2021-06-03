/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/range-sum-of-bst/
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
    int sum = 0;

  public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        rangeSumBSTUtil(root, low, high);
        return sum;
    }
    void rangeSumBSTUtil(TreeNode *root, int &low, int &high) {
        if (!root) {
            return;
        }
        int val = root->val;
        if (root->val > high) {
            rangeSumBSTUtil(root->left, low, high);
        } else if (root->val < low) {
            rangeSumBSTUtil(root->right, low, high);
        } else {
            sum += val;
            rangeSumBSTUtil(root->left, low, high);
            rangeSumBSTUtil(root->right, low, high);
        }
    }
};