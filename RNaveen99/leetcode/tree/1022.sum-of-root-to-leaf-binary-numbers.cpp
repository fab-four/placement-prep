/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeafUtil(root, 0);
    }
    
    int sumRootToLeafUtil(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        sum = sum * 2 + root -> val;
        if (!root -> left && !root -> right) {
            return sum;
        }
        return sumRootToLeafUtil(root -> left, sum) + sumRootToLeafUtil(root -> right, sum);
    }
};
