/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return bstFromPreorderUtil(preorder, 0, preorder.size() - 1);
    }
    TreeNode *bstFromPreorderUtil(vector<int> &preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int val = preorder[left];
        int firstGreater = -1;
        for (int i = left + 1; i <= right; i++) {
            if (preorder[i] > val) {
                firstGreater = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(val);
        root->left =
            bstFromPreorderUtil(preorder, left + 1, firstGreater == -1 ? right : firstGreater - 1);
        if (firstGreater != -1) {
            root->right = bstFromPreorderUtil(preorder, firstGreater, right);
        }

        return root;
    }
};

class Solution {
  public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int i = 0;
        TreeNode *root = new TreeNode(preorder[i++]);
        stack<TreeNode *> s;
        s.emplace(root);

        while (i < preorder.size()) {
            int val = preorder[i++];
            TreeNode *temp = new TreeNode(val);

            TreeNode *top = s.top();
            if (val < top->val) {
                top->left = temp;
            } else {
                TreeNode *prev = nullptr;
                while (!s.empty() && s.top()->val < val) {
                    prev = s.top();
                    s.pop();
                }
                prev->right = temp;
            }
            s.emplace(temp);
        }
        return root;
    }
};

class Solution {
  public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int i = 0;
        return bstFromPreorderUtil(preorder, i, INT_MAX);
    }

    TreeNode *bstFromPreorderUtil(vector<int> &preorder, int &i, int bound) {
        if (i >= preorder.size() || preorder[i] > bound) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorderUtil(preorder, i, root->val);
        root->right = bstFromPreorderUtil(preorder, i, bound);

        return root;
    }
};