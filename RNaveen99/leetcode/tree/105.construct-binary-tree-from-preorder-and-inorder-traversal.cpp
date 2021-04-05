/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    int preorder_start = 0;
    unordered_map<int, int> preorder_to_inorder;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorder_start = 0;
        int inorder_end = inorder.size();
        
        for (int i = 0; i < inorder_end; i++) {
            preorder_to_inorder.insert({inorder[i], i});
        }
        
        return buildTreeUtil(preorder, inorder_start, inorder_end - 1);
    }
    
    TreeNode* buildTreeUtil(vector<int>& preorder, int inorder_start, int inorder_end) {
        
        if (inorder_start > inorder_end) {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(preorder[preorder_start]);
        int root_index_inorder = preorder_to_inorder[preorder[preorder_start]];
        preorder_start++;

        
        root -> left = buildTreeUtil(preorder, inorder_start, root_index_inorder - 1);
        
        root -> right = buildTreeUtil(preorder, root_index_inorder + 1, inorder_end);
        
        return root;
    }
};
