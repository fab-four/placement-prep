/**
 * Author: Naveen Rohilla
 * User: RNaveen99
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        // inorderRecursive(root, inorder);
        inorderIter(root, inorder);
        return inorder;
    }
    
    void inorderRecursive(TreeNode* root, vector<int> & inorder) {
        if (root == NULL) {
            return;
        }
        inorderRecursive(root -> left, inorder);
        inorder.push_back(root -> val);
        inorderRecursive(root -> right, inorder);

    }
    void inorderIter(TreeNode* root, vector<int> & inorder) {
        stack <TreeNode*> s;
        
        while (root || ! s.empty()) {
            while (root){
                s.push(root);
                root = root -> left;
            }
            root = s.top();
            inorder.push_back(root -> val);
            root = root -> right;
            s.pop();
        }
    }
};
