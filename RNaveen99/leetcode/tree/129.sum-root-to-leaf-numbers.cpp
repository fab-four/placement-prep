/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int totalSum = 0;
    int sum = 0;

  public:
    int sumNumbers(TreeNode *root) {
        sumNumbersUtil(root);
        return totalSum;
    }

    void sumNumbersUtil(TreeNode *root) {
        if (!root)
            return;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            totalSum += sum;
        } else {
            sumNumbersUtil(root->left);
            sumNumbersUtil(root->right);
        }
        sum = (sum - root->val) / 10;
    }
};

class Solution {
    int totalSum = 0;

  public:
    int sumNumbers(TreeNode *root) {
        sumNumbersUtil(root, 0);
        return totalSum;
    }

    void sumNumbersUtil(TreeNode *root, int sum) {
        if (!root)
            return;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            totalSum += sum;
        } else {
            sumNumbersUtil(root->left, sum);
            sumNumbersUtil(root->right, sum);
        }
    }
};