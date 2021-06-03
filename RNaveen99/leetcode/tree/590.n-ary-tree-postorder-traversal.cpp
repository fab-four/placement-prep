/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    vector<int> result;

  public:
    vector<int> postorder(Node *root) {
        postorderUtil(root);
        return result;
    }
    void postorderUtil(Node *root) {
        if (root == nullptr) {
            return;
        }
        for (Node *child : root->children) {
            postorderUtil(child);
        }
        result.push_back(root->val);
    }
};

class Solution {
  public:
    vector<int> postorder(Node *root) {
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
            for (int i = 0; i < current->children.size(); i++) {
                if (current->children[i] != nullptr) {
                    s.emplace(current->children[i]);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
  public:
    vector<int> postorder(Node *root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        stack<pair<Node *, int>> s;
        s.emplace(root, 0);
        while (!s.empty()) {
            // auto &[node, index] = s.top();
            Node *node = s.top().first;
            int &index = s.top().second;
            if (index == node->children.size()) {
                result.emplace_back(node->val);
                s.pop();
            } else {
                s.emplace(node->children[index], 0);
                index++;
            }
        }
        return result;
    }
};