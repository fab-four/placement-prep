/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   :
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
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
  Node *flatten(Node *head) {
    if (!head)
      return head;
    Node *current = head;
    while (current) {
      if (current->child) {
        Node *temp = current->next;
        current->next = current->child;
        Node *cCurrent = current->child;
        cCurrent->prev = current;
        current->child = NULL;
        while (cCurrent->next)
          cCurrent = cCurrent->next;
        cCurrent->next = temp;
        if (temp)
          temp->prev = cCurrent;
      }
      current = current->next;
    }
    return head;
  }
};