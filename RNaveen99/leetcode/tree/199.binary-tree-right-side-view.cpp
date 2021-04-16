/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSide;

  public:
    vector<int> rightSideView(TreeNode *root) {
        rightSideViewUtil(root, 0);
        return rightSide;
    }
    void rightSideViewUtil(TreeNode *root, int depth) {
        if (!root)
            return;

        if (depth == rightSide.size()) {
            rightSide.emplace_back(root->val);
        }
        depth++;
        rightSideViewUtil(root->right, depth);
        rightSideViewUtil(root->left, depth);
    }
};