/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/unique-binary-search-trees-ii/
 */

// We start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. So if we pick i-th
// node as the root, the left subtree will contain elements 1 to (i-1), and the right subtree will contain
// elements (i+1) to n.
// we use recursive calls to get back all possible trees for left and right subtrees
// And combine them in all possible ways with the root.

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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode *>();
        return genTrees(1, n);
    }
    vector<TreeNode *> genTrees(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        } else if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        vector<TreeNode *> leftSubtree, rightSubtree;
        for (int i = start; i <= end; i++) {
            leftSubtree = genTrees(start, i - 1);
            rightSubtree = genTrees(i + 1, end);
            for (auto lnode : leftSubtree) {
                for (auto rnode : rightSubtree) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};