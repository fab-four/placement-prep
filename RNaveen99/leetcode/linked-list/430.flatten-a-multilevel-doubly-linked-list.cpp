/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (! head) {
            return head;
        }
        Node* p = head;
        stack <Node*> s;
        
        while (head || ! s.empty()) {
            if (head -> child) {
                if (head -> next) {
                    s.push(head -> next);
                }
                head -> child -> prev = head;
                head -> next = head -> child;
                head -> child = NULL;
            } else if (head -> next == NULL && ! s.empty()) {
                head -> next = s.top();
                head -> next -> prev = head;
                s.pop();
            }
            head = head -> next;
        }
        return p;
    }
    
    Node* flatten2(Node* head) {
        if (! head) {
            return head;
        }
        Node* p = head;
        while (head) {
            if (head -> child) {
                Node* child_tail = head -> child;
                Node* nextNode = head -> next;
                
                while (child_tail -> next) {
                    child_tail = child_tail -> next;
                }
                
                child_tail -> next = nextNode;
                if (nextNode) {
                    nextNode -> prev = child_tail;
                }
                head -> next = head -> child;
                head -> child -> prev = head;
                
                head -> child = NULL;
            }
            head = head -> next;
        }
        return p;
    }
};
