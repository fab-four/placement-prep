/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sum-of-left-leaves/
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
    int sum;

  public:
    int sumOfLeftLeaves(TreeNode *root) {
        sum = 0;
        sumOfLeftLeavesUtil(root);
        return sum;
    }
    void sumOfLeftLeavesUtil(TreeNode *root, bool leftChild = false) {
        if (!root)
            return;
        if (!root->left && !root->right && leftChild) {
            sum += root->val;
            return;
        }
        sumOfLeftLeavesUtil(root->left, true);
        sumOfLeftLeavesUtil(root->right, false);
    }
};

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
    int sumOfLeftLeaves(TreeNode *root) { return sumOfLeftLeavesUtil(root); }
    int sumOfLeftLeavesUtil(TreeNode *root, bool leftChild = false) {
        if (!root)
            return 0;
        if (!root->left && !root->right && leftChild) {
            return root->val;
        }
        return sumOfLeftLeavesUtil(root->left, true) + sumOfLeftLeavesUtil(root->right, false);
    }
};