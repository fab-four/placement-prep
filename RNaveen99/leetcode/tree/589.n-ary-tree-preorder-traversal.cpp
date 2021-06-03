/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
  public:
    vector<int> preorder(Node *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<Node *> s;
        s.emplace(root);
        while (!s.empty()) {
            Node *current = s.top();
            s.pop();
            result.emplace_back(current->val);
            for (int i = current->children.size() - 1; i >= 0; i--) {
                if (current->children[i] != nullptr) {
                    s.emplace(current->children[i]);
                }
            }
        }
        return result;
    }
};

class Solution {
    vector<int> result;

  public:
    vector<int> preorder(Node *root) {
        preorderUtil(root);
        return result;
    }
    void preorderUtil(Node *root) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        for (Node *child : root->children) {
            preorderUtil(child);
        }
    }
};