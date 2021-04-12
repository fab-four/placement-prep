/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-search-tree-iterator/
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

// The implementation of BST iterator is very similar to binary search tree Inorder traversal.
// Inorder using stack and two while loop. However, in the iterator, the first while condition
// become hasNext() and the code inside the first while condition become next().

class BSTIterator {
    stack<TreeNode *> s;
    TreeNode *node;

  public:
    BSTIterator(TreeNode *root) { node = root; }

    int next() {
        while (node) {
            s.emplace(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        int result = node->val;
        node = node->right;
        return result;
    }

    bool hasNext() { return node || !s.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */