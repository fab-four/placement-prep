/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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

// Create a node TreeNode(pre[preIndex]) as the root.

// Becasue root node will be lastly iterated in post order,
// if root.val == post[postIndex],
//      it means we have constructed the whole tree,

// If we haven't completed constructed the whole tree, So we recursively constructFromPrePost for left sub
// tree and right sub tree.

// And finally, we'll reach the posIndex that root.val == post[posIndex].
// We increment postIndex and return our root node.

class Solution {
    int preIndex = 0;
    int postIndex = 0;

  public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        TreeNode *root = new TreeNode(pre[preIndex]);
        preIndex++;
        if (root->val != post[postIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[postIndex])
            root->right = constructFromPrePost(pre, post);
        postIndex++;
        return root;
    }
};

// We will preorder generate TreeNodes, push them to stack and postorder pop them out.
// Iterate on pre array and construct node one by one.
// save the current path of tree.
// If we meet a same value in the pre and post, it means we complete the construction for current subtree. We
// pop it from stack.
class Solution {
  public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        stack<TreeNode *> s;
        s.push(new TreeNode(pre[0]));
        TreeNode *root = s.top();

        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode *node = new TreeNode(pre[i]);
            while (s.top()->val == post[j])
                s.pop(), j++;
            if (s.top()->left == NULL)
                s.top()->left = node;
            else
                s.top()->right = node;
            s.push(node);
        }
        return root;
    }
};