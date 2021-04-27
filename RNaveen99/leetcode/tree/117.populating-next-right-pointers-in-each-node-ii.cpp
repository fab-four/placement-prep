/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
    Node *connect(Node *root) {
        Node *currRoot = root;
        while (currRoot) {
            Node *curr = currRoot;
            while (curr) {
                Node *node = nullptr;
                if (curr->left && curr->right) {
                    curr->left->next = curr->right;
                    node = curr->right;
                } else if (curr->left || curr->right) {
                    node = curr->left ? curr->left : curr->right;
                }
                Node *nextNode = curr->next;
                while (nextNode && !nextNode->left && !nextNode->right) {
                    nextNode = nextNode->next;
                }
                if (nextNode && node) {
                    if (nextNode->left && nextNode->right) {
                        node->next = nextNode->left;
                    } else {
                        node->next = nextNode->left ? nextNode->left : nextNode->right;
                    }
                }
                curr = curr->next;
            }
            while (currRoot && !currRoot->left && !currRoot->right) {
                currRoot = currRoot->next;
            }
            if (currRoot) {
                if (currRoot->left) {
                    currRoot = currRoot->left;
                } else {
                    currRoot = currRoot->right;
                }
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
    Node *connect(Node *root) {
        Node *currLevelNode = root;
        Node *prevNode = nullptr;
        Node *nextLevel = nullptr;

        while (currLevelNode) {
            while (currLevelNode) {
                if (currLevelNode->left) {
                    if (prevNode) {
                        prevNode->next = currLevelNode->left;
                    } else {
                        nextLevel = currLevelNode->left;
                    }
                    prevNode = currLevelNode->left;
                }
                if (currLevelNode->right) {
                    if (prevNode) {
                        prevNode->next = currLevelNode->right;
                    } else {
                        nextLevel = currLevelNode->right;
                    }
                    prevNode = currLevelNode->right;
                }
                currLevelNode = currLevelNode->next;
            }
            currLevelNode = nextLevel;
            nextLevel = nullptr;
            prevNode = nullptr;
        }
        return root;
    }
};