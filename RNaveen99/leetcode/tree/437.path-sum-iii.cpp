/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/path-sum-iii/
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
    unordered_map<int, int> m;
    int result = 0;

  public:
    int pathSum(TreeNode *root, int targetSum) {
        m[0]++;
        pathSumUtil(root, targetSum, 0);
        return result;
    }
    void pathSumUtil(TreeNode *root, int targetSum, int c_sum) {
        if (!root)
            return;

        c_sum += root->val;
        int residualSum = c_sum - targetSum;
        if (m.find(residualSum) != m.end()) {
            result += m[residualSum];
        }
        m[c_sum]++;
        pathSumUtil(root->left, targetSum, c_sum);
        pathSumUtil(root->right, targetSum, c_sum);

        m[c_sum]--;
    }
};