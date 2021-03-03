/**
 * Author: Naveen Rohilla
 * User: RNaveen99
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        // preorderRecursive(root, preorder);
        preorderIter(root, preorder);
        return preorder;
    }
    void preorderRecursive(TreeNode* root, vector<int> & preorder) {
        if (root == NULL) {
            return;
        }
        preorder.push_back(root -> val);
        preorderRecursive(root -> left, preorder);
        preorderRecursive(root -> right, preorder);

    }
    void preorderIter(TreeNode* root, vector<int> & preorder) {
        stack <TreeNode*> s;
        
        while (root || ! s.empty()) {
            while (root){
                preorder.push_back(root -> val);
                s.push(root);
                root = root -> left;
            }
            root = s.top();
            root = root -> right;
            s.pop();
        }
    }
};
