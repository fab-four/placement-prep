/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxSum = INT_MIN;

  public:
    int maxPathSum(TreeNode *root) {
        maxPathSumUtil(root);
        return maxSum;
    }
    int maxPathSumUtil(TreeNode *root) {
        if (!root)
            return 0;

        int left = maxPathSumUtil(root->left);
        int right = maxPathSumUtil(root->right);

        int max1 = max(max(left, right) + root->val, root->val);

        int maxRoot = max(max1, left + root->val + right);

        maxSum = max(maxSum, maxRoot);

        return max1;
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
    int maxSum = INT_MIN;

  public:
    int maxPathSum(TreeNode *root) {
        maxPathSumUtil(root);
        return maxSum;
    }
    int maxPathSumUtil(TreeNode *root) {
        if (!root)
            return 0;

        int left = max(maxPathSumUtil(root->left), 0);
        int right = max(maxPathSumUtil(root->right), 0);

        maxSum = max(maxSum, left + root->val + right);

        return max(left, right) + root->val;
    }
};