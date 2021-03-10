/**
 * Author: Naveen Rohilla
 * User  : RNaveen99
 * Link  : https://leetcode.com/problems/path-sum/
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumUtil(root, 0, targetSum);
    }
    
    bool hasPathSumUtil(TreeNode* root, int sum, int & targetSum) {
        if (!root) {
            return false;
        }
        
        sum = sum + root -> val;
        
        if (!root -> left && !root -> right) {
            return sum == targetSum;
        }
        
        return hasPathSumUtil(root -> left, sum, targetSum) || hasPathSumUtil(root -> right, sum, targetSum);
    }
};
