/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/copy-list-with-random-pointer/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        insertDuplicateNode(head);
        connectRandomPointer(head);
        return separateList(head);
    }
    void insertDuplicateNode(Node *head) {
        while (head) {
            Node *temp = new Node(head->val);
            temp->next = head->next;
            head->next = temp;
            head = head->next->next;
        }
    }
    void connectRandomPointer(Node *head) {
        while (head) {
            head->next->random = head->random ? head->random->next : nullptr;
            head = head->next->next;
        }
    }
    Node *separateList(Node *head) {
        Node *head2 = head ? head->next : nullptr;
        while (head) {
            Node *temp = head->next;
            head->next = head->next->next;
            temp->next = head->next ? head->next->next : nullptr;
            head = head->next;
        }
        return head2;
    }
};