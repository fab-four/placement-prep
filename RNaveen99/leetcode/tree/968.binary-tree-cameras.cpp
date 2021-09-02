/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-cameras/
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
    int cameras;
    enum status { COVERED, NOT_COVERED, HAS_CAMERA };

  public:
    int minCameraCover(TreeNode *root) {
        cameras = 0;
        return minCameraCoverUtil(root) == NOT_COVERED ? ++cameras : cameras;
    }
    status minCameraCoverUtil(TreeNode *root) {
        if (!root) {
            return COVERED;
        }
        status left = minCameraCoverUtil(root->left);
        status right = minCameraCoverUtil(root->right);

        if (left == NOT_COVERED || right == NOT_COVERED) {
            cameras++;
            return HAS_CAMERA;
        }
        if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return COVERED;
        }
        return NOT_COVERED;
    }
};