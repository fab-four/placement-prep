/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> paths;

  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        binaryTreePathsUtil(root, "");
        return paths;
    }

    void binaryTreePathsUtil(TreeNode *root, string path) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            path += to_string(root->val);
            paths.emplace_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        binaryTreePathsUtil(root->left, path);
        binaryTreePathsUtil(root->right, path);
    }
};