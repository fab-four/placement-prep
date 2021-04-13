// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return nullptr;
    }
    Node *node_copy = new Node(node->val);
    unordered_map<Node *, Node *> copy_map;
    copy_map[node] = node_copy;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
      Node *cur = q.front();
      q.pop();
      for (const auto &neigh : cur->neighbors) {
        if (copy_map.find(neigh) == copy_map.end()) {
          copy_map[neigh] = new Node(neigh->val);
          q.push(neigh);
        }
        copy_map[cur]->neighbors.push_back(copy_map[neigh]);
      }
    }
    return node_copy;
  }
};
