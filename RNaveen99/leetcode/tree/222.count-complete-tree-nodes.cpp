/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;

        int leftHeight = 0;
        TreeNode *tempRoot = root;
        while (tempRoot) {
            leftHeight++;
            tempRoot = tempRoot->left;
        }
        int rightHeight = 0;
        tempRoot = root;
        while (tempRoot) {
            rightHeight++;
            tempRoot = tempRoot->right;
        }
        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};