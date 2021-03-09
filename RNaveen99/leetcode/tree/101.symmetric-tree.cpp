/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root -> left, root -> right);
    }
    
    bool checkSymmetric(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (!leftSubtree && !rightSubtree) {
            return true;
        }
        if (leftSubtree && rightSubtree) {
            return (leftSubtree -> val == rightSubtree -> val) &&
                checkSymmetric(leftSubtree -> left, rightSubtree -> right) &&
                checkSymmetric(leftSubtree -> right, rightSubtree -> left);
        }
        return false;
    }
};
