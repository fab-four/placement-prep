/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    int postorder_start;
    unordered_map<int, int> postorder_to_inorder;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorder_start = 0;
        int inorder_end = inorder.size();
        
        postorder_start = postorder.size() - 1;
        
        for (int i = 0; i < inorder_end; i++) {
            postorder_to_inorder.insert({inorder[i], i});
        }
        
        return buildTreeUtil(postorder, inorder_start, inorder_end - 1);
    }
    
    TreeNode* buildTreeUtil(vector<int>& postorder, int inorder_start, int inorder_end) {
        
        if (inorder_start > inorder_end) {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(postorder[postorder_start]);
        int root_index_inorder = postorder_to_inorder[postorder[postorder_start]];
        postorder_start--;

        root -> right = buildTreeUtil(postorder, root_index_inorder + 1, inorder_end);        
        root -> left = buildTreeUtil(postorder, inorder_start, root_index_inorder - 1);
        
        return root;
    }
};
