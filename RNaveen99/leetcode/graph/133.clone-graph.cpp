/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/clone-graph/
 */

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
        unordered_map<Node *, Node *> hash;
        createNodes(node, hash);
        linkNodes(node, hash);
        return hash[node];
    }

    void createNodes(Node *node, unordered_map<Node *, Node *> &hash) {
        if (!node)
            return;

        // node already created
        if (hash.find(node) != hash.end()) {
            return;
        }
        hash[node] = new Node(node->val);
        for (Node *eachNeighbor : node->neighbors) {
            createNodes(eachNeighbor, hash);
        }
    }

    void linkNodes(Node *node, unordered_map<Node *, Node *> &hash) {
        if (!node)
            return;
        for (Node *eachNeighbor : node->neighbors) {
            // if neighbor is not in root's list then add it
            if (find(hash[node]->neighbors.begin(), hash[node]->neighbors.end(), hash[eachNeighbor]) ==
                hash[node]->neighbors.end()) {
                hash[node]->neighbors.emplace_back(hash[eachNeighbor]);
            }
            // if root is not in neighbor's list
            if (find(hash[eachNeighbor]->neighbors.begin(), hash[eachNeighbor]->neighbors.end(),
                     hash[node]) == hash[eachNeighbor]->neighbors.end()) {
                linkNodes(eachNeighbor, hash);
            }
        }
    }
};