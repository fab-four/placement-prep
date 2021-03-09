/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Status {
        int count;
        TreeNode* root;
    };
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q).root;
    }
    
    Status findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return {0, NULL};
        }
        
        Status leftLCA = findLCA(root -> left, p, q);
        if (leftLCA.count == 2) {
            return leftLCA;
        }
        
        Status rightLCA = findLCA(root -> right, p, q);
        if (rightLCA.count == 2) {
            return rightLCA;
        }
        
        int count = leftLCA.count + rightLCA.count + (root == p) + (root == q);
        
        return {count, count == 2 ? root : nullptr };
    }
    
    
};
